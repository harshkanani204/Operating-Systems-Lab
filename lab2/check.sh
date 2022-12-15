#!/bin/bash
FILE1=$1
FILE2=$2
Number=$3
cmp -s "$FILE1" "$FILE2"
if [ $? -eq 0 ]
then
    echo "Test Case $Number Passed"
else
    echo "Test Case $Number Failed"
fi