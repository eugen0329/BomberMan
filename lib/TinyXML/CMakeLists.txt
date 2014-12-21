cmake_minimum_required(VERSION 2.8.8)

project(TXP)



file(GLOB_RECURSE SRC_NAMES *.cpp)


message(STATUS ${SRC_NAMES}) 
add_library(tinyxml STATIC ${SRC_NAMES})
