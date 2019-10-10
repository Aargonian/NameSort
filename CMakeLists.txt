cmake_minimum_required(VERSION 3.0)
project(NameSort C)

set(CMAKE_C_STANDARD 11)

add_executable(NameSort src/main.c
                        src/name_string.c
        src/string_vector.c
                        include/name_string.h
                        include/string_vector.h)

target_include_directories(NameSort PRIVATE ${CMAKE_SOURCE_DIR}/include)