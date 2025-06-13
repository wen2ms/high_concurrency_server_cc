cmake_minimum_required(VERSION 3.14)

project(high_concurrency_server_cc)

include_directories(
    ${PROJECT_SOURCE_DIR}/common
    ${PROJECT_SOURCE_DIR}/http
    ${PROJECT_SOURCE_DIR}/reactor
    ${PROJECT_SOURCE_DIR}/tcp
    ${PROJECT_SOURCE_DIR}/thread)

add_subdirectory(common)
add_subdirectory(http)
add_subdirectory(reactor)
add_subdirectory(tcp)
add_subdirectory(thread)

link_libraries(common http reactor tcp thread)

add_executable(high_concurrency_server_cc main.cpp)