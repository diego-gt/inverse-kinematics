cmake_minimum_required(VERSION 3.18)

project(InverseKinematics VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use with LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SOURCES
    src/Conversion.h
    src/Point3.h
    src/Vector3.h
    src/Joint.h
    src/Link3.h
    src/main.cpp
)

add_executable(
    ik
    ${SOURCES}
)