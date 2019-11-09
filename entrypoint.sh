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

first_param=${1:?Please provide a parameter (url|command)}

if ! [[ $first_param =~ ^(http|/) ]]; then
  exec "$@"
fi

__download_code

source ~/.bashrc

snip g++ -Wall --std=c++17 code.cpp &&
  tst ./a.out
