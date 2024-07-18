cmake_minimum_required(VERSION 3.5)

project(AddLib)
set(CMAKE_DEBUG_POSTFIX d)

add_library(${PROJECT_NAME} SHARED
    AddLib.h
    AddLib.cpp
    AddLib_global.h
    AddLibInterface.h
)
add_library(Lib::AddLib ALIAS ${PROJECT_NAME})

# 添加导出宏
target_compile_definitions(${PROJECT_NAME} PRIVATE SCHEDULER_LIBRARY)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION install)
