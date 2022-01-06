cmake_minimum_required(VERSION 3.21)
project(OSRT)

set(CMAKE_CXX_STANDARD 14)

add_executable(OSRT main.cpp config.h core.c core.h types.h link.h link.c)
