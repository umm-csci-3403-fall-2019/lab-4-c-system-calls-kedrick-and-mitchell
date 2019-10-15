#!/bin/bash

echo "There were $(find $1 -type d | wc -l) directories."
echo "There were $(find $1 -type f | wc -l) regular files."


