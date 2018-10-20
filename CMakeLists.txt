cmake_minimum_required (VERSION 2.6)
project (wmalloc)

include_directories(include)

add_library(wmalloc src/wmalloc.c)