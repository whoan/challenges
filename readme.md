# Challenges

This repo collects some exercises I've made to practice algorithms and data structures.

Most of them are from [Hacker Rank](https://www.hackerrank.com/) and you can find a link to the exercices in each source file.

*Disclaimer: I am not proud of all of them, but I try not to modify old files to see the evolution in the newest files I submit. eg: cleaner code, more performant code due to use of right data structures, algorithms, etc...*

## Test your C++ algorithms with docker

I created a simple function to test my/your algorithms with the help of docker. Suppose you already placed this function in your initialization (eg: in .bashrc file):

```bash
curl https://raw.githubusercontent.com/whoan/challenges/master/dtest.sh
```
```bash
dtest() {
  declare -a tst_volumes
  local param
  for param in "$@"; do
    if [[ $param =~ ^/ ]]; then
      tst_volumes+=(-v"$param":"$param")
    elif [ -f "$param" ]; then
      param=${param#~}
      tst_volumes+=(-v"$PWD/$param:/app/$param")
    fi
  done
  docker run -ti --rm --volume=tst-cache:/root/.cache "${tst_volumes[@]}" whoan/tst:latest "$@"
}
```

Now, you can test your local files or any file from internet like this:

```
$ dtest min-coin-change/bottom-up.cpp
Downloading snippet: https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/base.cpp
Running: g++ -Wall --std=c++17 /tmp/tmp.gACmjC.cpp
Running test 'min-coin-change'
/root/.cache/tst/min-coin-change/input-00.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-01.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-02.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-03.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-04.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-05.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-06.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-07.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-08.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-09.txt -> SUCCEDED
```

```
$ dtest min-coin-change/crazy-for-code.cpp
Running: g++ -Wall --std=c++17 /tmp/tmp.MmcBjI.cpp
Running test 'min-coin-change'
/root/.cache/tst/min-coin-change/input-00.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-01.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-02.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-03.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-04.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-05.txt -> FAILED
Expected output:
7

Current output:
-2147483642

/root/.cache/tst/min-coin-change/input-06.txt -> FAILED
Expected output:
4

Current output:
-2147483647

/root/.cache/tst/min-coin-change/input-07.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-08.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-09.txt -> SUCCEDED
```

Or directly with a web url:

```
$ dtest https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/bottom-up.cpp
Running: g++ -Wall --std=c++17 /tmp/tmp.JnGmkn.cpp
Running test 'min-coin-change'
/root/.cache/tst/min-coin-change/input-00.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-01.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-02.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-03.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-04.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-05.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-06.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-07.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-08.txt -> SUCCEDED
/root/.cache/tst/min-coin-change/input-09.txt -> SUCCEDED
```

> You can clean the cache volume with this line if you want to force to download datasets: `docker volume rm tst-cache`
