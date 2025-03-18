cmake_minimum_required(VERSION 3.23)

project(fileSystemManager)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES fileSystemManager.cpp)
set(HEADERS fileSystemManager.hpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
