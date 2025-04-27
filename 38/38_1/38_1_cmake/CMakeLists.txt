cmake_minimum_required(VERSION 3.5)

project(38_1_cmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets Multimedia MultimediaWidgets
              REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        sound_button.cpp
        sound_button.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(38_1_cmake
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 38_1_cmake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(38_1_cmake SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(38_1_cmake
            ${PROJECT_SOURCES}
        )
    endif()
endif()



#target_link_libraries(38_1_cmake Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)

#target_link_libraries(38_1_cmake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
#    Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)

target_link_libraries(38_1_cmake Qt${QT_VERSION_MAJOR}::Widgets
                                 Qt${QT_VERSION_MAJOR}::Core
                                 Qt${QT_VERSION_MAJOR}::Multimedia
                                 Qt${QT_VERSION_MAJOR}::MultimediaWidgets)


