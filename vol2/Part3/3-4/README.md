# 第 3 部 IoT システム開発をハンズオン解説

## 第 4 章 遠隔監視 - 画像の定期アップロード

### 4-1 イントロダクション

#### 4-1-2 必要なもの

- IoT 体験キット〜簡易監視カメラ: https://soracom.jp/products/kit/camera_kit/

### 4-3 STEP2 USB カメラのセットアップ

#### 4-3-1 USB カメラの接続

```console
v4l2-ctl --list-devices
```

#### 4-3-2 USB カメラでの撮影

```console
sudo apt install fswebcam -y
cd /home/pi/
fswebcam -q --device /dev/video0 /home/pi/picture.jpg
python3 -m http.server 8000
```

### 4-5 STEP4 SORACOM Harvest Files へ画像をアップロード

#### 4-5-3 Harvest Files へ画像をアップロードする

- 撮影した画像のアップロード
  ```console
  curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@/home/pi/picture.jpg' harvest-files.soracom.io
  ```
- 画像の撮影とアップロードを一括で実行
  ```console
  fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
  ```

#### 4-5-5 定期的にアップロードする (cron 設定)

- cron 設定ファイルの作成と 10 分おきの撮影とアップロード設定
  ```console
  sudo touch /etc/cron.d/upload-photo
  echo "*/10 * * * * pi fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io &> /dev/null" | sudo tee /etc/cron.d/upload-photo > /dev/null
  ```
- cron 設定ファイルの編集
  ```console
  sudo vi /etc/cron.d/upload-photo
  ```

### 4-6 STEP5 SORACOM Lagoon で可視化

#### 4-6-1 SORACOM Harvest Files と SORACOM Harvest Data の連携を有効にする

```console
fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
```
