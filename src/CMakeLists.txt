cmake_minimum_required(VERSION 3.5)
project(chess_lib)

find_package(QT NAMES Qt5 COMPONENTS Widgets Gui REQUIRED)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        chessboard.cpp
        chessboard.h
        chesslogic.cpp
        chesslogic.h
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui)