echo off

SET OUTPUT="output.txt"

if exist %OUTPUT% del /f %output%
NameSort.exe "Sort Me.txt" > %OUTPUT%
fc %OUTPUT% Sorted.txt
if %errorlevel% EQU 0 (echo "Success") else ( echo "Failure")
