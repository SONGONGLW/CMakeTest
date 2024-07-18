cmake_minimum_required(VERSION 3.5)

project(Test)

add_subdirectory(Src)
add_subdirectory(AddLib)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
