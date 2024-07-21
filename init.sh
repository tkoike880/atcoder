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

function judge() {
  g++ main.cpp
  if poetry run oj t; then
    acc s
  fi
}
