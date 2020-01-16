# 第 4 部 Appendix

## 第 1 章 SORACOM Access Management のベストプラクティス

### 1-3 権限の変更

#### 1-3-1 権限の追加と削除

- API リファレンス: https://dev.soracom.io/jp/docs/api/
- アクセス権限設定のためのパーミッション構文: https://dev.soracom.io/jp/docs/sam_permission/

#### 1-3-2 設定の確認

- SORACOM サービスと API の対応が知りたい (2019 年版): https://blog.soracom.jp/blog/2019/12/24/asksoracom002/

### 1-5 SAM デフォルト権限

- SAM のデフォルト権限: https://dev.soracom.io/jp/docs/default_permissions/

### 1-6 SORACOM API 利用における SAM の利用手順

#### 1-6-2 API の利用

- API リファレンス: https://dev.soracom.io/jp/docs/api/

## 第 3 章 LPWA 通信における送信データ形式とその最適化

### 3-2 LPWA 通信の特徴と課題

- 地域毎のメッセージサイズと送信に必要な時間の例: https://build.sigfox.com/payload#a-technicality-padding-bits

### 3-5 バイナリパーサーの利用

- バイナリパーサー詳細 | SORACOM Users: https://dev.soracom.io/jp/docs/binary_parser/

#### 3-5-1 バイナリーパーサーのテスト方法

- Binary Parser Playgroud: https://binary-parser-playground.soracom.io/

## 第 4 章 トラブルシューティングガイド

### 4-4 構成するコンポーネントの状況を収集・確認して切り分け

#### 4-4-2 問題発生コンポーネントの切り分け

- plan01s: 各国で接続可能な通信キャリア: https://soracom.jp/files/soracom-air-global.csv
- plan-D (NTT ドコモ) サービスエリア: https://www.nttdocomo.co.jp/area/
- plan-K (KDDI) サービスエリア: https://www.au.com/mobile/area/
- plan-KM1 (KDDI) サービスエリア: https://www.kddi.com/business/mobile/m2m-solution/iot-lpwa/area/
- SORACOM IoT SIM(グローバルカバレッジ)に関するお知らせ（カバレッジ拡張、通信障害など）: https://soracom.jp/areainfo/
- 工事のお知らせ | お知らせ | NTT ドコモ: https://www.nttdocomo.co.jp/info/construction/
- My au 障害・メンテナンス情報｜ au: https://www.au.com/my-au/maintenance/
- SORACOM Status: https://soracom.statuspage.io/

#### 4-5-1 公式ドキュメントと FAQ

- dev.soracom.io: https://dev.soracom.io/
- IoT プラットフォーム 株式会社ソラコム - サポート: https://soracom.zendesk.com/hc/ja
- セルラーベストプラクティスガイド: https://pages.soracom.jp/BPG_Soracom-Air-For-Cellular.html

#### 4-5-2 技術サポートへの問い合わせ

- Web サイト: https://soracom.jp
- Twitter: https://twitter.com/SORACOM_PR
- Facebook: https://ja-jp.facebook.com/soracom.jp/
- SORACOM ユーザーコンソール: https://console.soracom.io/#/?coverage_type=jp
- Ask SORACOM: https://blog.soracom.jp/blog/categories/asksoracom/

## 第 5 章 SORACOM CLI の使い方

- 公式 Web ドキュメントの SORACOM CLI 利用ガイド: https://dev.soracom.io/jp/docs/cli_guide/

### 5-2 SORACOM CLI 利用のための準備

#### 5-2-1 SORACOM CLI のインストール

```console
brew tap soracom/soracom-cli
brew install soracom-cli
```

#### 5-2-2 SORACOM CLI を用いたプロファイルの作成

```console
LANG=ja soracom configure
```

### 5-3 使用例

#### 5-3-1 特定の SIM について日ごとのデータ通信量を取得する

- スクリプトのダウンロード・実行
  ```console
  curl -sO https://raw.githubusercontent.com/soracom/soracom-book/master/vol2/Appendix/soracom-cli-guide/dailyStatSum.sh
  bash ./dailyStatSum.sh 44010xxxxxxxxxx
  ```

#### 5-3-2 特定のタグが付与された SIM の速度クラスを一括で変更する

- タグの付与 https://dev.soracom.io/jp/start/console/#tags
- スクリプトのダウンロード・実行
  ```console
  curl -sO https://raw.githubusercontent.com/soracom/soracom-book/master/vol2/Appendix/soracom-cli-guide/updateSpeedClassWithTag.sh
  bash ./updateSpeedClassWithTag.sh
  ```

#### 5-3-3 TIPS soracom auth コマンドを用いて API key, API token を発行する

- スクリプトのダウンロード・実行
  ```console
  curl -sO https://raw.githubusercontent.com/soracom/soracom-book/master/vol2/Appendix/soracom-cli-guide/authAndUpdateSpeedClassWithTag.sh
  bash ./authAndUpdateSpeedClassWithTag.sh
  ```

## 第 6 章 ソラコムに関する情報源やコンタクト方法

### 6-1 ソラコム主催イベント

- ソラコム イベント・セミナー: https://soracom.jp/event/
- SORACOM へのお問い合わせ: https://soracom.jp/contact/contactsales/
- SORACOM 無料個別相談会: https://pages.soracom.jp/sales-consulting-seminar.html

### 6-3 見積もりツール

- 料金見積もりツール: https://calculator.soracom.io/#/ja

### 6-4 ユーザーコミュニティ「SORACOM UG」

- Twitter: https://twitter.com/soracomug
- Facebook: https://www.facebook.com/soracomug
- Connpass: https://soracomug-tokyo.connpass.com/
