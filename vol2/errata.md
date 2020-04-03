# 公式ワークブック SORACOM 実装ガイド 正誤表

書籍に以下の誤りがございました。お詫びして訂正いたします。

## 第 1 版 第 1 刷

|  部 |  章 | ページ | 誤                   | 正                   |
| --: | --: | -----: | -------------------- | -------------------- |
|   2 |   4 |     94 | `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"` | `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"` (2020年3月以降 Homebrew のセットアップ手順が変更されました([Homebrew/install#256](https://github.com/Homebrew/install/pull/256))。2020年3月16日時点では書籍に記載の手順も動作しますが非推奨になったため今後動作しない可能性があります) |
|   3 |   6 |    226 | Access Resource Name | Amazon Resource Name |
|   3 |   8 |    279 | `curl -OL https://github.com/soracom/soracom-book/blob/master/vol2/Part3/3-8/inventory-agent.tar` |  `curl -L "https://github.com/soracom/soracom-book/blob/master/vol2/Part3/3-8/inventory-agent.tar?raw=true" -o inventory-agent.tar` |
