#!/bin/bash

# プロファイルとカバレッジタイプを指定
PROFILE="default"
COVERAGE_TYPE="jp"

# 速度クラスを変更するタグと変更後の速度クラスを指定
TAG_NAME="city"
TAG_VALUE="tokyo"
SPEED_CLASS="s1.minimum"

# プロファイルがない時はエラーを返す
if [ ! -e "${HOME}/.soracom/${PROFILE}.json" ]
then
  echo "no profile"
  exit 1
fi

# soracom auth でプロファイルから apiKey と token を発行
auth_key_id=$(cat ${HOME}/.soracom/${PROFILE}.json | jq -r '.authKeyId')
auth_key=$(cat ${HOME}/.soracom/${PROFILE}.json | jq -r '.authKey')
auth_info=$(soracom auth --auth-key-id=${auth_key_id} --auth-key=${auth_key})

# authKeyId, authKey が誤っている場合はエラーを返す
if [ -z "${auth_info}" ]
then
  echo "wrong authKeyId or authKey"
  exit 1
fi

# apiKey と token を取得
api_key=$(echo ${auth_info} | jq -r '.apiKey')
token=$(echo ${auth_info} | jq -r '.token')

# 以後毎回 apiKey と token を指定するため、認証回数が減る
common_option="--api-key=${api_key} --api-token=${token} --coverage-type=${COVERAGE_TYPE}"

# 指定されたタグ の SIM 一覧を取得
subs=`soracom subscribers list --tag-name ${TAG_NAME} --tag-value ${TAG_VALUE} ${common_option} | jq -r .[].imsi`

# 指定したタグの SIM がない場合はエラーを返す
if [ -z "${subs}" ]
then
  echo "no SIM with the specified tag"
  exit 1
fi

# 取得した SIM の速度クラスを指定された速度にする
echo "${subs}" | while read line
do
  soracom subscribers update-speed-class --imsi ${line} --speed-class ${SPEED_CLASS} ${common_option} | jq '[.imsi, .speedClass]'
done