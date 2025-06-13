cmake_minimum_required(VERSION 3.14)

project(common)

aux_source_directory(./ SRC)

add_library(common ${SRC})