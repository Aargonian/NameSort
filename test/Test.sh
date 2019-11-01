#!/bin/bash

OUTPUT="output.txt"
OUTPUT2="output2.txt"
OUTPUT3="output3.txt"
OUTPUT4="output4.txt"
OUTPUT5="output5.txt"
OUTPUT6="output6.txt"

rm -f $OUTPUT
rm -f $OUTPUT2
rm -f $OUTPUT3
rm -f $OUTPUT4
rm -f $OUTPUT5
rm -f $OUTPUT6

./NameSort "Sort Me.txt" > $OUTPUT
./NameSort "Sort Me 2.txt" > $OUTPUT2
./NameSort -d "Sort Me.txt" > $OUTPUT3
./NameSort -d "Sort Me 2.txt" > $OUTPUT4
./NameSort --descending "Sort Me.txt" > $OUTPUT5
./NameSort --descending "Sort Me 2.txt" > $OUTPUT6

STATUS=0

diff "Sorted.txt" $OUTPUT
if [ $? -eq 0 ]; then
    echo "Test 1 Success"
else
    echo "Test 1 Failure"
    STATUS=1
fi

diff "Sorted 2.txt" $OUTPUT2
if [ $? -eq 0 ]; then
    echo "Test 2 Success"
else
    echo "Test 2 Failure"
    STATUS=1
fi

diff "Sorted 3.txt" $OUTPUT3
if [ $? -eq 0 ]; then
    echo "Test 3 Success"
else
    echo "Test 3 Failure"
    STATUS=1
fi

diff "Sorted 4.txt" $OUTPUT4
if [ $? -eq 0 ]; then
    echo "Test 4 Success"
else
    echo "Test 4 Failure"
    STATUS=1
fi

diff "Sorted 3.txt" $OUTPUT5
if [ $? -eq 0 ]; then
    echo "Test 5 Success"
else
    echo "Test 5 Failure"
    STATUS=1
fi

diff "Sorted 4.txt" $OUTPUT6
if [ $? -eq 0 ]; then
    echo "Test 6 Success"
else
    echo "Test 6 Failure"
    STATUS=1
fi

exit $STATUS
