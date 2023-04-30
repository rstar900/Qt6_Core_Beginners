cmake_minimum_required(VERSION 3.14)

project(09_Q_Property_Example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(09_Q_Property_Example
  main.cpp
  source.cpp
  destination.cpp
  source.h
  destination.h
)
target_link_libraries(09_Q_Property_Example Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 09_Q_Property_Example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
