# 第 3 部 IoT システム開発をハンズオン解説

## 第 9 章 SORACOM Krypton を使ったプロビジョニング

### 9-2 STEP1 AWS IAM 資格情報の作成

- AWS Management Console https://console.aws.amazon.com/console/home

### 9-7 STEP6 動作確認

- 必要なソフトウェアのインストール
  ```console
  sudo apt update
  sudo apt install mosquitto-clients jq
  ```
- Krypton API による証明書の発行
  ```console
  curl -X POST https://krypton.soracom.io:8036/v1/provisioning/aws/iot/bootstrap > cert.json
  ```
- 取得したデータの出力
  ```console
  cat cert.json | jq .privateKey -r > thing-private-key.pem
  cat cert.json | jq .certificate -r > cert.pem
  wget https://www.amazontrust.com/repository/AmazonRootCA1.pem -O rootCA.pem
  ```
- AWS IoT Core への接続
  ```console
  mosquitto_pub --cafile rootCA.pem --cert cert.pem --key thing-private-key.pem \
  -p 8883 -q 1 -d -t topic/test -i clientid2 -m "Hello, World" -h <AWS IoTのエンドポイント名>
  ```
