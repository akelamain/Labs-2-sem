cmake_minimum_required(VERSION 3.23)

project(lab7)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp Executor.cpp)
set(HEADERS Executor.hpp)

add_subdirectory(University)
add_subdirectory(MyStack)
add_subdirectory(Functions)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/University
    ${CMAKE_CURRENT_SOURCE_DIR}/MyStack
    ${CMAKE_CURRENT_SOURCE_DIR}/Functions
)

target_link_libraries(${PROJECT_NAME}
    University
    MyStack
    Functions
)
