cmake_minimum_required(VERSION 2.8.8)
project(myproject)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

######################
# Check dependencies
######################

find_package(SFML 2 REQUIRED system window graphics audio)
if(NOT SFML_FOUND)
    message(SEND_ERROR "Failed to find SFML library")
    return()
endif()

if(NOT UNIX)
    message(STATUS "WARNING: Hasn't been tested on other OS than Unix-like")
endif()


set(TARGET_NAME "bin")
set(TARGET ${TARGET_NAME})
set(LIB_DIR "lib/TinyXML")
set(SRC_DIR "src/")

set (CMAKE_CXX_FLAGS "-Wall -pedantic-errors -g -std=c++11") 


add_subdirectory(${LIB_DIR})


file(GLOB_RECURSE SRC_NAMES ${SRC_DIR}*.cpp)
add_executable(${TARGET} ${SRC_NAMES})

include_directories( 
    ${SFML_INCLUDE_DIR} 
    ${PROJECT_BINARY_DIR} 
    ${SRC_DIR}
    ${LIB}
    lib
)

target_link_libraries(
    ${TARGET}
    ${SFML_LIBRARIES} 
    tinyxml
)


##################
# Install target
##################

install(TARGETS ${TARGET} DESTINATION ${TARGET_NAME})
