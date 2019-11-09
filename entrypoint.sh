#!/usr/bin/env bash

__curl_http_error() {
  local content_file
  content_file=${1:?Please provide the retrieved content by curl}
  local status_code
  status_code=${2:?Please provide an HTTP status code}
  [[ $(cut -f1 -d: "$content_file") == "$status_code" ]]
}

code_url=${1:?Please provide code url to compile and test}

if [ "$code_url" == bash ]; then
  bash
  exit
fi

source ~/.bashrc

curl --silent "$code_url" -o code.cpp

if __curl_http_error code.cpp 404; then
  echo "Code could not be downloaded" >&2
  exit 1
fi

snip g++ -Wall --std=c++17 code.cpp &&
  tst ./a.out
