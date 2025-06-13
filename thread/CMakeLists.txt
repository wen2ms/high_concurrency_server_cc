cmake_minimum_required(VERSION 3.14)

project(thread)

aux_source_directory(./ SRC)

add_library(thread ${SRC})