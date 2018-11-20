cmake_minimum_required(VERSION 3.9)
project(CS\ 2110\ HW10)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(src MAIN_SOURCES)
AUX_SOURCE_DIRECTORY(src/images SUB_SOURCES)

add_executable(
        HW10
        ${MAIN_SOURCES}
        ${SUB_SOURCES}
        )
