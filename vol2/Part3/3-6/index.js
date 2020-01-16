//////// 設定が必要な項目です。 ////////
const tableName = "stock"; // DynamoDBのテーブル名
const itemName = "coffee"; // 在庫管理する項目名
const threshold = 5; // メール通知する在庫数
const addCount = 20; // 補充する数
const mailFromAddress = ""; // 送信元のメールアドレス
const mailToAddress = ""; // 通知先のメールアドレス
//////// ここまで ////////

const aws = require('aws-sdk');
const ses = new aws.SES({region: 'us-west-2'});
const dynamo = new aws.DynamoDB.DocumentClient();

exports.handler = async (event, context) => {
    try {
        // 現在の在庫量を取得
        const result = await dynamo.get({
            TableName: tableName,
            Key: { "name": itemName }
        }).promise();
        // 在庫量を１減らす
        let newCount = result.Item.count - 1;

        // 在庫量がしきい値に達したら通知
        if (newCount == threshold) {
            const subject = itemName + "の在庫が不足してきました";
            const body = itemName + "の在庫量が" + newCount + "になりました。在庫を補充してください。";
            const params = {
                Destination: {
                    ToAddresses: [ mailToAddress ]
                },
                Message: { // メールのタイトルと本文を指定します。
                    Subject: { Data: subject },
                    Body: { Text: { Data: body } }
                },
                Source: mailFromAddress
            };
            await ses.sendEmail(params).promise();
            console.log("メール通知しました。");
            
            // 補充した数字を保存する。
            newCount += addCount;
        }
        
        // 在庫量を更新
        await dynamo.put({
            "TableName": tableName,
            "Item": {
                "name": itemName,
                "count": newCount
            }
        }).promise();
    } catch (e) {
        console.log("エラーが起きました。");
        console.log(e);
    }
    return {
        statusCode: 200,
        body: "ok"
    };
};

