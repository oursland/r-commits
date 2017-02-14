cmake_minimum_required(VERSION 3.0)

project(r-commits VERSION 1.0.0 LANGUAGES CXX)

add_definitions(
  -std=c++11
  -Wall
  -O1
  -g
  )

add_executable(process
  process.cpp
  )
