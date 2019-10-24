cmake_minimum_required(VERSION 3.0)
project(NameSort C)

set(CMAKE_C_STANDARD 11)

add_executable(NameSort src/main.c
                        src/name_string.c
        src/string_vector.c
                        include/name_string.h
                        include/string_vector.h include/file_io.h src/file_io.c include/constants.h)

# Copy executable to test directory after compilation for ease of testing
add_custom_command(TARGET NameSort POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:NameSort> ${CMAKE_SOURCE_DIR}/test/)

target_include_directories(NameSort PRIVATE ${CMAKE_SOURCE_DIR}/include)

# After everything has been built, we want to automatically run tests as part of the build
IF(Win32)
    add_custom_command(
            TARGET NameSort
            POST_BUILD
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test
            COMMAND cmd /c Test.cmd
    )
ELSE()
    add_custom_command(
            TARGET NameSort
            POST_BUILD
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test
            COMMAND bash -c ./Test.sh
    )
ENDIF()
