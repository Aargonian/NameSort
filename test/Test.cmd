echo off

SET OUTPUT="output.txt"
SET OUTPUT2="output2.txt"

if exist %OUTPUT% del /f %OUTPUT%
NameSort.exe "Sort Me.txt" > %OUTPUT%
fc %OUTPUT% "Sorted.txt"
if %errorlevel% EQU 0 (echo "Success") else ( echo "Failure")

if exist %OUTPUT2% del /f %OUTPUT2%
NameSort.exe "Sort Me 2.txt" > %OUTPUT2%
fc %OUTPUT2% "Sorted 2.txt"
if %errorlevel% EQU 0 (echo "Success") else ( echo "Failure")
