echo off
NameSort.exe "Sort Me.txt" > Output.txt
fc Output.txt Sorted.txt
if %errorlevel% EQU 0 (echo "Success") else ( echo "Failure")
