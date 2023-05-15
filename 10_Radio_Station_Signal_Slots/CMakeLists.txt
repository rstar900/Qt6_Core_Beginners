cmake_minimum_required(VERSION 3.14)

project(10_Radio_Station_Signal_Slots LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(10_Radio_Station_Signal_Slots
  main.cpp
  radio.h
  channel.h
  radio.cpp
  channel.cpp
)
target_link_libraries(10_Radio_Station_Signal_Slots Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 10_Radio_Station_Signal_Slots
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
