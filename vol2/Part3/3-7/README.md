# 第 3 部 IoT システム開発をハンズオン解説

## 第 7 章 業務システムへのセキュアアクセス

### 7-2 STEP1 LTE タブレットでの SIM のセットアップ

#### 7-2-1 iPad（iOS 端末）

- APN 構成プロファイルのダウンロードページ: https://dev.soracom.io/jp/start/begin_soracom/#apn

### 7-3 AWS での Web アプリケーションサーバーの設定

#### 7-3-1 Elastic Beanstalk の設定

- AWS Management Console: https://console.aws.amazon.com/console/home
- Elastic Beanstalk: https://ap-northeast-1.console.aws.amazon.com/elasticbeanstalk/home?region=ap-northeast-1#/gettingStarted

#### 7-5-4 コラム VPG のアウトバウンドルーティングフィルター

- タブレットから `3.0.0.0` - `3.255.255.255` の IP アドレスへのアクセスを拒否する設定
  ```console
  soracom vpg --vpg-id xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx set-routing-filter --body '[{"action": "deny", "ipRange": "3.0.0.0/8"}]'
  ```
- VPG アウトバウンドルーティングフィルターを設定する | Getting Started | SORACOM Users: https://dev.soracom.io/jp/start/vpg_routing_filter/
