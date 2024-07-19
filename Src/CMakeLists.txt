cmake_minimum_required(VERSION 3.5)

project(Test)

add_executable(Test Test.cpp)

target_include_directories(Test PRIVATE ${CMAKE_SOURCE_DIR}/AddLib)

target_link_libraries(${PROJECT_NAME} Lib::AddLib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION install)
