cmake_minimum_required(VERSION 3.17)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(SurgicalOperationApp main.cpp ${MY_INCLUDE_DIR}/surg.h 
    ${MY_INCLUDE_DIR}/custom_types.h surg.cpp)
target_include_directories(SurgicalOperationApp PUBLIC ${MY_INCLUDE_DIR})

