cmake_minimum_required(VERSION 3.17)
project("30_2_1_App" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 6ea2dec23c3df14ac3b27b7d2d6bbff0cb7ba1b0) 

FetchContent_MakeAvailable(cpr)



add_executable(30_2_1_App main.cpp 
               ${MY_INCLUDE_DIR}/str.h
               str.cpp)

target_link_libraries(30_2_1_App PRIVATE cpr::cpr)
target_include_directories(30_2_1_App PUBLIC ${MY_INCLUDE_DIR})




