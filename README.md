# NameSort
This program is designed to take as input a txt file containing a list of names, separated by line breaks, and sorts 
them first by length and then alphabetically.

As this program is written in pure C (C11 to be exact) with a CMake build script, you will require a C Compiler and 
CMake to build it. The program doesn't, however, rely on any external libraries aside from the C Standard Library 
available with all C Compilers, so that is all that is required.

# Unix Build 
If you are on a Unix-based system, your system's cc/gcc compiler should be enough to build the program. Make sure you 
have build tools and cmake installed. Create a 'build' directory, cd into it using the shell of your choice, then 
invoke cmake, and finally invoke make.

mkdir build
cd build
cmake ../
make

After you have built the program, you can run it from the build directory or move it to a location of your choice.
The program needs the file to sort passed to it. I have included a copy of the 'Sort Me.txt' test file within the 
'test' folder of the project, for testing purposes. To test the program on it, simply run the following commands 
from within the build directory:

./NameSort "../test/Sort Me.txt"

# Windows Build

If you are on Windows, you will require Visual Studio 2017 or later, as this project
does use CMake and, unless you want to use the CMake custom tools, Visual Studio did not have support for CMake 
before this version. Also make sure that your installation of Visual Studio 2017 has the C++ Tools for Desktop
Development modules installed. If you don't have these, you should be able to use the Visual Studio Installer to
modify your copy with these modules. Also make sure your copy is fully up to date, as earlier versions had notable
issues building CMake Projects.

To build the project, just open Visual Studio, and choose Open->CMake from the file menu. Navigate to the project 
folder, and select the CMakeLists.txt file. The project should open in Visual Studio and, after a bit of indexing, 
settle. Once indexed, change the run configuration to NameSort. It may initially say "Select Startup Item".

Once selected, use the Build menu and select "Build". The project should Build successfully. 

Unfortunately, Visual Studio still does not support setting run configurations for Cmake project, so there is no way
to run the program successfully and pass it the file. Instead, you will have to open Command Prompt or Powershell
and run the program the hard way. 

The default configuration will have placed the built exe in the following folder:

"C:\Users\<UserName>\CMakeBuilds\<UUID OF Project>\build\x64-Debug (default)"

Navigate to this folder and open a command prompt/powershell, or navigate to it directly from within the shell. I also
recommend copying the "Sort Me.txt" file into this directory, so you don't have to pass a very long path name to the 
program.

To run the program, it will be almost the same as on Unix:

./NameSort.exe "./Sort Me.txt"

# Testing

Testing is currently very simple. All test files are contained in the test subdirectory. Testing is currently automated
by a batch/cmd/bash script which can be run automatically by building the project with CMake. The CMake system should
automatically determine what system you are on and run the appropriate script.

If you wish to manually run the test, simply open your command prompt or terminal in the test directory and run the 
Test.cmd or Test.sh file. Make sure you have built the executable and moved it to the test directory first.
