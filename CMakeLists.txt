cmake_minimum_required(VERSION 3.10)
project(AutoPong VERSION 1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/raylib)

add_executable(${PROJECT_NAME} src/main.cpp src/game.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE src/include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
