cmake_minimum_required(VERSION 3.20)
project(insertion_sort)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exec 
	main.cpp
	insertion_sort.cpp
    tests.cpp
)