cmake_minimum_required(VERSION 3.17)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(SurgicalOperationApp main.cpp 
               ${MY_INCLUDE_DIR}/circle.h
               ${MY_INCLUDE_DIR}/rectangle.h
               ${MY_INCLUDE_DIR}/triangle.h
               ${MY_INCLUDE_DIR}/shape.h
               ${MY_INCLUDE_DIR}/global_types.h
               ${MY_INCLUDE_DIR}/output_functions.h
               circle.cpp 
               rectangle.cpp
               triangle.cpp
               output_functions.cpp)
               
target_include_directories(SurgicalOperationApp PUBLIC ${MY_INCLUDE_DIR})

