/*
Wio LTE Temp, Humi, Moisture sample sketch
Copyright 2020 SORACOM, Inc.
All rights reserved.
*/

#include <WioLTEforArduino.h>
#include <GroveDriverPack.h>

#define RECEIVE_TIMEOUT (10000)
#define INTERVAL        (60000)

WioLTE Wio;
int moistureSensorPin = WIOLTE_A4;
int sensorValue = 0;

GroveBoard Board;
GroveTempHumiDHT11 TempHumi(&Board.D38);

void setup() {
  delay(200);
  SerialUSB.begin(115200);
  SerialUSB.println("### START");

  SerialUSB.println("### I/O Initialize.");
  Wio.Init();

  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyLTE(true);
  Wio.PowerSupplyGrove(true);
  delay(500);

  pinMode(moistureSensorPin, INPUT_ANALOG);
  Board.D38.Enable();
  TempHumi.Init();

  SerialUSB.println("### Turn on or reset.");
  if (!Wio.TurnOnOrReset()) {
    SerialUSB.println("### ERROR! ###");
    return;
  }

  SerialUSB.println("### Connecting to \"soracom.io\".");
  if (!Wio.Activate("soracom.io", "sora", "sora")) {
    SerialUSB.println("### ERROR! ###");
    return;
  }
  Wio.LedSetRGB(64, 64, 64);  // White

  SerialUSB.println("### Setup completed.");
}

void sendEnvData() {
  char data[1024];
  snprintf(data, sizeof(data),
    "{\"temperature\":%.2f,\"humidity\":%.2f,\"moisture\":%d}",
    TempHumi.Temperature,
    TempHumi.Humidity,
    sensorValue);

  SerialUSB.println("### Socket Open.");

  int connectId;
  connectId = Wio.SocketOpen("uni.soracom.io", 23080, WIOLTE_UDP);
  if (connectId < 0) {
    SerialUSB.println("### Socket Open Error! ###");
    delay(INTERVAL);
  }

  SerialUSB.println("### Send.");
  SerialUSB.print("Send:");
  SerialUSB.println(data);
  if (!Wio.SocketSend(connectId, data)) {
    SerialUSB.println("### Data Send Error! ###");
    goto err_close;
  }

  SerialUSB.println("### Receive.");
  int length;
  length = Wio.SocketReceive(connectId, data, sizeof (data), RECEIVE_TIMEOUT);
  if (length < 0) {
    SerialUSB.println("### Data Receive Error!! ###");
    Wio.LedSetRGB(64, 0, 0);  // Red
    goto err_close;
  }
  if (length == 0) {
    SerialUSB.println("### Receive Timeout! ###");
    goto err_close;
  }
  SerialUSB.print("Receive:");
  SerialUSB.println(data);
  Wio.LedSetRGB(0, 64, 0);  // Green

  delay(INTERVAL);

err_close:
  SerialUSB.println("### Socket Close.");
  if (!Wio.SocketClose(connectId)) {
    SerialUSB.println("### Socket Close Error! ###");
    Wio.LedSetRGB(64, 0, 0);  // Red
    delay(INTERVAL);
  }
}

void loop() {
  TempHumi.Read();
  sensorValue = analogRead(moistureSensorPin);
  SerialUSB.print("Current humidity = ");
  SerialUSB.print(TempHumi.Humidity);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(TempHumi.Temperature);
  SerialUSB.print("C  ");
  SerialUSB.print("Moisture = ");
  SerialUSB.println(sensorValue);

  sendEnvData();
  delay(INTERVAL);
}
