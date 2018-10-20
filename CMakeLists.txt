cmake_minimum_required (VERSION 2.6)
project (wmalloc)

set(CUTEST_DIR ${PROJECT_SOURCE_DIR}/cutest)

include_directories(include)

add_library(wmalloc src/wmalloc.c)

add_subdirectory(test)