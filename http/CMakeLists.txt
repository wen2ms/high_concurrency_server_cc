cmake_minimum_required(VERSION 3.14)

project(http)

aux_source_directory(./ SRC)

add_library(http ${SRC})