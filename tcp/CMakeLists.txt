cmake_minimum_required(VERSION 3.14)

project(tcp)

link_libraries(common http reactor)

aux_source_directory(./ SRC)

add_library(tcp ${SRC})