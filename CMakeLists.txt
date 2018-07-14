cmake_minimum_required(VERSION 3.10)

project(Explosive_Race)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Explosive_Race
        Car.cpp
        Car.h
        Dynamite.cpp
        Dynamite.h
        Main.cpp)

file(GLOB LIBRARIES "C:/Users/Luca/Desktop/Explosive Race/alld42.dll")
message("LIBRARIES = ${LIBRARIES}")
target_link_libraries(Explosive_Race ${LIBRARIES})
