cmake_minimum_required(VERSION 2.6)
project(helloworld)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

aux_source_directory(. DIR_SRCS)
set(INC_DIR /usr/local/Cellar/libevent/2.1.8/include)
set(LINK_DIR /usr/local/Cellar/libevent/2.1.8/lib)


include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(event)
add_executable(helloworld ${DIR_SRCS})
