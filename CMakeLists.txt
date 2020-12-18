cmake_minimum_required(VERSION 3.17)

project(Graphics)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${VENDOR_DIR}/glfw/include
        ${VENDOR_DIR}/glad/include
)

add_subdirectory(${PROJECT_SOURCE_DIR})
add_subdirectory(${VENDOR_DIR})