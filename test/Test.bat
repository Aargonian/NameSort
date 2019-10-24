
NameSort.exe "Sort Me.txt" > Output.txt
fc Output.txt Sorted.txt
if errorlevel 1 {
    echo "Test Failure"
} else {
    echo "Test Success"
}