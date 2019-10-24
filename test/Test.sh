#!/bin/bash

OUTPUT="output.txt"
OUTPUT2="output2.txt"

rm -f $OUTPUT
rm -f $OUTPUT2

./NameSort "Sort Me.txt" > $OUTPUT
./NameSort "Sort Me 2.txt" > $OUTPUT2

diff "Sorted.txt" $OUTPUT
if [ $? -eq 0 ]; then
    echo "Test 1 Success"
else
    echo "Test 1 Failure"
fi

diff "Sorted 2.txt" $OUTPUT2
if [ $? -eq 0 ]; then
    echo "Test 2 Success"
else
    echo "Test 2 Failure"
fi
