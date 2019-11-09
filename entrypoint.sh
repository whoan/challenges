#!/usr/bin/env bash

__curl_http_error() {
  local content_file
  content_file=${1:?Please provide the retrieved content by curl}
  local status_code
  status_code=${2:?Please provide an HTTP status code}
  [[ $(cut -f1 -d: "$content_file") == "$status_code" ]]
}

__download_code() {
  curl --silent "$first_param" -o code.cpp
  if __curl_http_error code.cpp 404; then
    echo "Code could not be downloaded" >&2
    exit 1
  fi
}

__is_url() {
  local param
  param=${1:?Please provide a parameter (url|command) to check}
  [[ $param =~ ^http ]]
}

__is_file() {
  local param
  param=${1:?Please provide a parameter (url|command) to check}
  [ -f "$param" ]
}

first_param=${1:?Please provide a parameter (url|command)}

if __is_url "$first_param"; then
  __download_code
  set - code.cpp
elif __is_file "$first_param"; then
  :
else
  exec "$@"
fi

# shellcheck disable=SC1090
source ~/.bashrc

snip g++ -Wall --std=c++17 "$@" &&
  tst ./a.out
