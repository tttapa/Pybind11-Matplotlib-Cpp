cmake_minimum_required(VERSION 3.4)
project(Pybind11-Matplotlib-Cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(pybind11 REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main pybind11::embed)