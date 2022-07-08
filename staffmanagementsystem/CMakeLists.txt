cmake_minimum_required(VERSION 3.21)
project(staffmanagementsystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(staffmanagementsystem main.cpp src/manager.cpp src/manager.h src/staff.h)
