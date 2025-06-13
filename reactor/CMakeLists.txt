cmake_minimum_required(VERSION 3.14)

project(reactor)

aux_source_directory(./ SRC)

add_library(reactor ${SRC})