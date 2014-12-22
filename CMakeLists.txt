cmake_minimum_required(VERSION 2.8.8)
project(myproject)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" ${CMAKE_MODULE_PATH})

set(LIB_DIR "lib")

# SFML 2 base UI framework
set(TGUI_SRC_DIR "${LIB_DIR}/TGUI")

# Small xml parser
set(TXML_SRC_DIR "${LIB_DIR}/TinyXML")

######################
# Check dependencies
######################
set(ERR_COUNTER 0)

find_package(SFML 2 REQUIRED system window graphics audio)
if(NOT SFML_FOUND)
    message(SEND_ERROR "Error: Failed to find SFML library")
    MATH(EXPR ERR_COUNTER ${ERR_COUNTER}+1)
endif()

if(NOT UNIX)
    message(STATUS "WARNING: Hasn't been tested on other OS than Unix-like")
endif()

if(NOT ERR_COUNTER EQUAL 0)
    return()
endif()

######################
#       General
######################



set(TARGET_NAME "bin")
set(TARGET ${TARGET_NAME})
set(SRC_DIR "src/")


set (CMAKE_CXX_FLAGS "-Wall -pedantic-errors -g -std=c++11") 


add_subdirectory(${TXML_SRC_DIR})


file(GLOB_RECURSE SRC_NAMES ${SRC_DIR}*.cpp)
add_executable(${TARGET} ${SRC_NAMES})

include_directories( 
    ${SFML_INCLUDE_DIR} 
    ${PROJECT_BINARY_DIR} 
    ${SRC_DIR}
    ${LIB_DIR}
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
