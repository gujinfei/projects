cmake_minimum_required(VERSION 2.6)
project(helloworld)

#add_definitions(-DUSE_BOOST)

#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

aux_source_directory(. DIR_SRCS)
set(INC_DIR  /usr/local/include)
set(LINK_DIR /usr/local/lib)


include_directories(${INC_DIR} ./common /usr/local/include)
add_subdirectory(common)

link_directories(${LINK_DIR})
#link_libraries(event)
add_executable(helloworld ${DIR_SRCS})
target_link_libraries(helloworld common)
#target_link_libraries(helloworld common -lboost_thread -lboost_system -lboost_thread)