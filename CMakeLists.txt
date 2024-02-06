cmake_minimum_required(VERSION 3.20)
project(RayTracing)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(RayTracing main.cpp ${SOURCES})
