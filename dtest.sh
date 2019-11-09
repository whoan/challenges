#!/usr/bin/env bash

dtest() {
  declare -a tst_volumes
  local param
  for param in "$@"; do
    if [[ $param =~ ^/ ]]; then
      tst_volumes+=(-v"$param":"$param")
    elif [ -f "$param" ]; then
      param=${param#~}
      tst_volumes+=(-v"$PWD/$param":/app/"$param":ro)
    fi
  done
  docker run -ti --rm --volume=tst-cache:/root/.cache "${tst_volumes[@]}" whoan/tst:latest "$@"
}
