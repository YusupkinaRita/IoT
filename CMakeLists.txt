cmake_minimum_required(VERSION 3.8)

project(IoT
LANGUAGES CXX)

set(CMAKE_SXX_FLAGS "{CMAKE_SXX_FLAGS} -std=c++17")

add_executable(main main.cpp)