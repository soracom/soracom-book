#!/bin/bash

# IMSI を指定
IMSI=$1
# 取得終了日
to_date=`date +%s`
# 遡る日数
AGO=60
epoch_ago=$((${AGO} * 24 * 3600))
# 取得開始日
from_date=$((${to_date} - ${epoch_ago}))

# 引数を指定していない場合はエラーを返す
if [ -z "${IMSI}" ]
then
  echo "no IMSI specified. Execute with 'dailyStatSum.sh [IMSI]'"
  exit 1
fi

# SIM のデータ通信量を取得
json=`soracom stats air get --imsi=${IMSI} --period=day --from=${from_date} --to=${to_date}`

# 速度クラスを取得
speed_classes=`echo ${json} | jq -r '.[].dataTrafficStatsMap | keys | .[]' | sort | uniq`

# 速度クラスごとに、日次のデータ通信量を表示
echo "${speed_classes}" | while read line
do
  echo ${line}
  option=".[] | select(.dataTrafficStatsMap.\"${line}\") | [.date, .dataTrafficStatsMap.\"${line}\".uploadByteSizeTotal, .dataTrafficStatsMap.\"${line}\".downloadByteSizeTotal] |@tsv"
  echo ${json} | jq -r "${option}" | column -t
done