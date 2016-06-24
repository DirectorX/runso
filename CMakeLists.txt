cmake_minimum_required(VERSION 3.5)
project(runso C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -Wall -ldl")

set(SOURCE_FILES src/main.c)

add_executable(runso ${SOURCE_FILES})
