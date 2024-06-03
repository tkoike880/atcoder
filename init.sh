alias acc="npx acc"
npx acc config oj-path $(poetry env info --path)/bin/oj
npx acc config default-task-choice all
npx acc login
poetry run oj login https://atcoder.jp/

function judge() {
  g++ main.cpp
  if poetry run oj t; then
    acc s
  fi
}
