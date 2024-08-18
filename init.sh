alias acc="npx acc"
alias oj="poetry run oj"

npx acc config oj-path $(poetry env info --path)/bin/oj
npx acc config default-task-choice all
npx acc login
poetry run oj login https://atcoder.jp/

SCRIPT_DIR=$(cd $(dirname ${BASH_SOURCE:-$0}); pwd)

function _chr() {
  [ "$1" -lt 256 ] || return 1
  printf "\\$(printf '%03o' "$1")"
}

function _ord {
  echo `printf "%d" \'$1`
}

function next() {
  local curdir=$(basename $(pwd))
  local cur=$(_ord "$curdir")
  local next=$(_chr $(($cur + 1)))
  cd ../$next
}

function prev() {
  local curdir=$(basename $(pwd))
  local cur=$(_ord "$curdir")
  local next=$(_chr $(($cur - 1)))
  cd ../$next
}

function build() {
  g++ -std=gnu++2b -O2 -DONLINE_JUDGE -DATCODER \
  -Wall -Wextra \
  -mtune=native -march=native \
  -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
  -I $SCRIPT_DIR/ac-library \
  -I $SCRIPT_DIR/lib \
  -o a.out main.cpp
}

function run() {
  ./a.out < test/sample-$1.in
}

function judge() {
  build
  if poetry run oj t; then
    acc s
  fi
}
