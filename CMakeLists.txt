
cmake_minimum_required(VERSION 3.18)

set( PROJECT "booklend")

set( PROJECT_VERSION_MAJOR "0" )
set( PROJECT_VERSION_MINOR "0" )
set( PROJECT_VERSION_PATCH "1" )
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
#set path of libs
set( JSONPATH "./lib/jsoncpp")
set( SQLAPIPATH "./lib/SQLAPI")
set( TGBOTPATH "./lib/tgbot-cpp/include")

project(${PROJECT})
configure_file(config.h.in config.h @ONLY)
file(GLOB SOURCES "./src/*.cpp")
#add_subdirectory(/usr/local/mysql/connector-c++-)
include_directories(booklend PUBLIC ./lib/SQLAPI/include)
include_directories(booklend PUBLIC ./lib/tgbot-cpp/include)
link_directories( ${SQLAPIPATH} )
find_library(SQLAPI sqlapi ${SQLAPIPATH} )
if(NOT SQLAPI)
  message("[Error] : sqlapi lib not found...! ")
endif()

link_directories(${JSONPATH})
link_directories(${TGBOTPATH})

add_subdirectory(./lib/jsoncpp)
add_subdirectory(./lib/tgbot-cpp)
include_directories(booklend PUBLIC ./include)
add_executable(main main.cpp ${SOURCES})
target_link_libraries( main sqlapi jsoncpp dl curl)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_compile_options(main PUBLIC -Wall)
