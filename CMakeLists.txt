cmake_minimum_required(VERSION 3.10)
project(Gauge)

set(CMAKE_CXX_STANDARD 17)

add_executable(gauge
src/main.cpp
src/lexer.cpp
src/parser.cpp
)