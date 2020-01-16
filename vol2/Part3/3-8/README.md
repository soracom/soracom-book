# 第 3 部 IoT システム開発をハンズオン解説

## 第 8 章 SORACOM Inventory を使った遠隔制御

- Ligtweight M2M について: https://www.omaspecworks.org/what-is-oma-specworks/iot/lightweight-m2m-lwm2m/

### 8-3 STEP2 Rasbperry Pi の Wi-Fi セットアップ

- Wi-Fi の設定
  ```console
  sudo nano /etc/wpa_supplicate/wpa_supplicant.conf
  ```
- 設定ファイルの編集
  ```
  network={
      ssid="利用するWifiのSSID"
      psk="利用するWifiのパスワード"
  }
  ```
- Wi-Fi インターフェースの再起動
  ```console
  sudo ifdown wlan0
  sudo ifup wlan0
  ```
- Raspberry Pi の再起動
  ```
  sudo reboot
  ```
- インターネットへの接続確認
  ```console
  ping www.soracom.jp
  ```

### 8-5 STEP4 JRE とサンプルエージェントの設定

- LwM2M クライアント実装
  - Eclipse Leshan: https://www.eclipse.org/leshan/
  - Eclipse Wakaama: https://github.com/eclipse/wakaama
  - Anjay: https://www.avsystem.com/products/anjay/
- SORACOM Inventory Agent for Java: https://github.com/soracom/soracom-inventory-agent-for-java
- AdoptOpenJDK: https://adoptopenjdk.net/
- サンプルアプリケーションのアーカイブの取得と展開用コマンド
  ```console
  curl -OL https://soracom-files.s3-ap-northeast-1.amazonaws.com/book2020/inventory-agent.tar
  tar xvf inventory-agent.tar
  cd inventory-agent
  ls
  ```

### 8-6 STEP5 サンプルエージェントの起動

デバイス ID と シークレットキー の部分は、STEP1 で SORACOM ユーザーコンソールから取得したデバイス ID およびシークレットキーをセットしてください。

```console
./start-agent.sh -i デバイスID -p シークレットキー -u jp.inventory.soracom.io
```

### 8-10 最後に

- サンプルエージェントのソースコード: https://github.com/soracom/soracom-book/blob/master/vol2/Part3/3-8/inventory-agent.tar
