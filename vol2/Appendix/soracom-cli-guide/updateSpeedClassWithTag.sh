#!/bin/bash

# 速度クラスを変更するタグと変更後の速度クラスを指定
TAG_NAME="city"
TAG_VALUE="tokyo"
SPEED_CLASS="s1.minimum"

# 指定されたタグの SIM 一覧を取得
subs=`soracom subscribers list --tag-name ${TAG_NAME} --tag-value ${TAG_VALUE} | jq -r .[].imsi`

# 指定したタグの SIM がない場合はエラーを返す
if [ -z "${subs}" ]
then
  echo "no SIM with the specified tag"
  exit 1
fi

# 取得した SIM の速度クラスを指定された速度にする
echo "${subs}" | while read line
do
  soracom subscribers update-speed-class --imsi ${line} --speed-class ${SPEED_CLASS} | jq '[.imsi, .speedClass]'
done
