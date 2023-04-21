cmake_minimum_required(VERSION 3.16.3)
project(Decodifica C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Decodifica
        rv_decoder.c)
