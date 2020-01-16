# 第 2 部 ハンズオンの準備

## 第 1 章 ハンズオンに必要なもの

### 1-2 ハンズオンで必要な IoT デバイス

- 簡易監視カメラキット: https://soracom.jp/products/kit/camera_kit/

## 第 2 章 アカウントの作成

### 2-1 SORACOM アカウント

#### 2-1-3 SORACOM ユーザーコンソールへアクセス

- ソラコム: https://soracom.jp
- ユーザーコンソール: https://console.soracom.io

#### 2-1-10 より安全に SORACOM を利用するために

- MFA (多要素認証) の設定および詳細: https://dev.soracom.io/jp/docs/mfa/

### 2-2 AWS アカウント

#### 2-2-3 STEP1 サインアップフォームの表示

- AWS: https://aws.amazon.com/jp/

#### 2-2-9 STEP7 アカウント作成の完了

- AWS: https://aws.amazon.com/jp/

#### 2-2-10 より安全に AWS を利用するために

- IAM のベストプラクティス: https://docs.aws.amazon.com/ja_jp/IAM/latest/UserGuide/best-practices.html

## 第 4 章 Wio LTE のセットアップ

### 4-1 Wio LTE 開発環境のセットアップ

#### 4-1-1 Wio LTE 開発環境のセットアップ（Windows 編）

- Arduino IDE: https://www.arduino.cc/en/main/software
- 追加のボードマネージャーの URL: `https://www.seeed.co.jp/package_SeeedJP_index.json`

#### 4-1-2 Arduino IDE のインストール（macOS 編）

- Arduino IDE: https://www.arduino.cc/en/main/software
- Homebrew: https://brew.sh/index_ja
- Homebrew のインストール:
  ```console
  /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  ```
- libusb のインストール:
  ```console
  brew install libusb
  ```
- 追加のボードマネージャーの URL: `https://www.seeed.co.jp/package_SeeedJP_index.json`

### 4-2 Wio LTE のセットアップ

- アクリルケース（クリアー）Grove IoT スターターキット for SORACOM（Wio LTE JP Version）用: https://www.switch-science.com/catalog/5662/

#### 4-2-3 Wio LTE 動作モード確認方法（Windows 編）

- Virtual COM Port デバイスドライバーのインストール: https://seeedjp.github.io/Wiki/Wio_LTE_for_Arduino/InstallVCOMDriver-ja.html
- Zadig: https://zadig.akeo.ie/

## 第 5 章 Raspberry Pi のセットアップ

### 5-3 Raspbian イメージのダウンロード

- Raspbian Buster Lite イメージ: https://www.raspberrypi.org/downloads/raspbian/

### 5-4 Raspbian イメージを書き込む

- balena 社 Ethcer: https://www.balena.io/etcher/

### 5-5 SSH の有効化と Wi-Fi の設定

- Raspberry Pi の SSH 設定ファイル: https://soracom-files.s3.amazonaws.com/raspbian_boot.zip

### 5-7 Raspberry Pi への接続（有線 LAN から SSH）

#### 5-7-1 Windows の場合の設定

- Tera Term: https://ja.osdn.net/projects/ttssh2/

#### 5-7-3 macOS/Linux の場合の設定

```console
ssh pi@raspberrypi.local
```

#### 5-7-5 パスワード設定

```console
passwd
```

## 第 6 章 USB モデムを Raspberry Pi へのセットアップ

- SORACOM プラットフォームに接続する
  ```console
  curl -O https://soracom-files.s3.amazonaws.com/setup_air.sh
  sudo bash setup_air.sh
  ```
- SORACOM プラットフォームとの接続を確認する
  ```console
  ping -c 4 metadata.soracom.io
  ```

## 第 7 章 SORACOM Lagoon のセットアップ

### 7-1 SORACOM Lagoon とは

- SORACOM Lagoon のご利用料金: https://soracom.jp/services/lagoon/price/
