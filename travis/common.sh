#!/bin/bash
function run()
{
  local exit_code=0
  examples=($(find $PWD/examples/ -name "*.pde" -o -name "*.ino"))

  local last="${examples[@]:(-1)}"

  for example in "${examples[@]}"; do

    local example_dir=$(dirname $example)

    local example_file=$(basename $example)

    echo "$example_file: "
    local sketch="$example_dir/$example_file"
    echo "$sketch"

    local build_stdout
    build_stdout=$(arduino ||verify $sketch 2>&1)

    if [ $? -ne 0 ]; then
      echo -e "\xe2\x9c\x96"
      echo -e "|||||||||||||||||||||||||||| DEBUG OUTPUT ||||||||||||||||||||||||||||\n"
      echo "$build_stdout"
      echo -e "\n"
      echo -e "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"

      exit_code=1

    else
      echo -e "\xe2\x9c\x93"
    fi
  done

  return $exit_code
}
