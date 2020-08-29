
cmake_minimum_required(VERSION 3.18)

set( PROJECT "booklend")

set( PROJECT_VERSION_MAJOR "0" )
set( PROJECT_VERSION_MINOR "0" )
set( PROJECT_VERSION_PATCH "1" )

set( CPP_CONNECTOR "/usr/local/mysql/connector-c++-/lib64/debug/")
project(${PROJECT})
configure_file(config.h.in config.h @ONLY)
file(GLOB SOURCES "./src/*.cpp")
#add_subdirectory(/usr/local/mysql/connector-c++-)
include_directories(booklend PUBLIC /usr/local/mysql/connector-c++-/include)
link_directories( ${CPP_CONNECTOR} )
find_library(CPP_CONN mysqlcppconn8 ${CPP_CONNECTOR} )
if(NOT CPP_CONN)
  message("[Error] : mysqlconnector lib not found...! ")
endif()

#add_library(cppcon PRIVATE ${CPP_CONNECTOR} ) 
include_directories(booklend PUBLIC ./include)
add_executable(main main.cpp ${SOURCES})
target_link_libraries( main mysqlcppconn8 )

