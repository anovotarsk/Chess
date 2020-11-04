cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64")

find_package(QT NAMES Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        chessboard.cpp
        chessboard.h
)

add_executable(test
        ${PROJECT_SOURCES}
)

target_link_libraries(test PRIVATE Qt5::Widgets Qt5::Gui)
