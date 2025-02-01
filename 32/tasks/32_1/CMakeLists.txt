cmake_minimum_required(VERSION 3.17)
project("32_1" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(32_1 main.cpp)

target_link_libraries(32_1 PRIVATE nlohmann_json::nlohmann_json)






















