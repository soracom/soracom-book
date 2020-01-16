/*
Wio LTE GPS sample sketch
Copyright 2020 SORACOM, Inc.
All rights reserved.
*/

#include <WioLTEforArduino.h>
#include <TinyGPS++.h>

WioLTE Wio;
TinyGPSPlus gps;

#define RECEIVE_TIMEOUT (10000)
#define INTERVAL        (60000)

void setup() {
  delay(200);
  SerialUSB.begin(115200);
  SerialUSB.println("### START");

  SerialUSB.println("### I/O Initialize.");
  Wio.Init();
  GpsBegin(&SerialUART);

  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyLTE(true);
  Wio.PowerSupplyGrove(true);
  delay(500);

  SerialUSB.println("### Turn on or reset.");
  if (!Wio.TurnOnOrReset()) {
    SerialUSB.println("### ERROR! ###");
    return;
  }
  Wio.LedSetRGB(64, 64, 64);  // White

  SerialUSB.println("### Connecting to \"soracom.io\".");
  if (!Wio.Activate("soracom.io", "sora", "sora")) {
    SerialUSB.println("### ERROR! ###");
    return;
  }

  SerialUSB.println("### Setup completed.");
}

HardwareSerial* GpsSerial;
void GpsBegin(HardwareSerial* serial) {
    GpsSerial = serial;
    GpsSerial->begin(9600);
}

void loop() {
  while (GpsSerial->available()) {
    if (gps.encode(GpsSerial->read())) {
    #ifdef WIO_DEBUG
      SerialUSB.println("NMEA encode is succeed");
      SerialUSB.print("LAT=");
      SerialUSB.println(gps.location.lat());
      SerialUSB.print("LON=");
      SerialUSB.println(gps.location.lng());
      SerialUSB.print("ALT(m)=");
      SerialUSB.println(gps.altitude.meters());
      SerialUSB.print("SPEED(km/h)=");
      SerialUSB.println(gps.speed.kmph());
      SerialUSB.print("Satellites=");
      SerialUSB.println(gps.satellites.value());
      SerialUSB.print("Chars=");
      SerialUSB.println(gps.charsProcessed());
      SerialUSB.print("Sentences-with-Fix=");
      SerialUSB.println(gps.sentencesWithFix());
      SerialUSB.print("Failed-checksum=");
      SerialUSB.println(gps.failedChecksum());
      SerialUSB.print("Passed-checksum=");
      SerialUSB.println(gps.passedChecksum());
    #endif
      if (gps.location.lat() == 0 || gps.location.lng() == 0) {
        SerialUSB.println("GPS is not ready, wating...");
      } else {
        sendLocationData();
      }
    } else {
      Wio.LedSetRGB(64, 0, 0);  // Red
    }
  }
  Wio.LedSetRGB(64, 0, 0);  // Red
}

void sendLocationData() {
  char data[1024];
  snprintf(data, sizeof(data),
    "{\"lat\":%lf,\"long\":%lf,\"alt\":%lf,\"kmph\":%lf,\"satellites\":%lu}",
    gps.location.lat(),
    gps.location.lng(),
    gps.altitude.meters(),
    gps.speed.kmph(),
    gps.satellites.value());

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
    delay(INTERVAL);
  }
}
