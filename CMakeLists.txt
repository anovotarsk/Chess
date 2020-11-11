cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64")

find_package(QT NAMES Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(src)

add_executable(${PROJECT_NAME}
        main.cpp
)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui)
target_link_libraries(${PROJECT_NAME} chess_lib)
