cmake_minimum_required(VERSION 3.20)

project(rayluz VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# list of compilation units
set(SOURCES
    src/main.cpp
    src/image_save.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})