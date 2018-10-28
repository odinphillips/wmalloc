# wmalloc unit tests (ctest)
set(srcs test_wmalloc_ctest.c)

add_executable(test_wmalloc_ctest ${srcs})
target_include_directories(test_wmalloc_ctest PUBLIC ${CTEST_DIR})
target_link_libraries(test_wmalloc_ctest PUBLIC wmalloc)