# 第 3 部 IoT システム開発をハンズオン解説

## 第 6 章 リアルタイム在庫通知

### 6-2 STEP1 実装方針の検討

- Amazon DRS (Dash Replenishment Service) 公式ドキュメント: https://developer.amazon.com/ja/docs/dash/replenishment-service.html

### 6-4 STEP3 AWS Lambda 関数の作成

- 追加するコード
  ```js
  exports.handler = async (event, context) => {
      console.log('event: %j', event);
      console.log('context: %j', context);
  ```
- コード全体
  ```js
  exports.handler = async (event, context) => {
    console.log("event: %j", event);
    console.log("context: %j", context);
    const response = {
      statusCode: 200,
      body: JSON.stringify("Hello from Lambda!")
    };
    return response;
  };
  ```

### 6-7 STEP6 通知の設定

- Amazon SES サンドボックスの外への移動: https://docs.aws.amazon.com/ja_jp/ses/latest/DeveloperGuide/request-production-access.html

### 6-9 STEP8 アプリケーションの実装

- index.js: https://github.com/soracom/soracom-book/blob/master/vol2/Part3/3-6/index.js
