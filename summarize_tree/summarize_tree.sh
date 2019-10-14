#!/bin/bash

path=$1

num_regular=$(find $path -type f | wc -l | xargs)
num_dir=$(find $path -type d| wc -l| xargs)

echo "There were "$num_regular" regular files."
echo "There were "$num_dir" directories."


