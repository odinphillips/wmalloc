# wmalloc unit tests
set(srcs ${CUTEST_DIR}/CuTest.c test_wmalloc.c)

add_executable(test_wmalloc ${srcs})
target_include_directories(test_wmalloc PUBLIC ${CUTEST_DIR})
target_link_libraries(test_wmalloc PUBLIC wmalloc)