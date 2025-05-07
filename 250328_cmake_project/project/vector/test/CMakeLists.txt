set(SOURCES
	test_vector.cpp
)

add_executable(vector_tests ${SOURCES})
target_link_libraries(vector_tests 
	gtest 
	vector_lib
)

add_test(vector_tests vector_tests)
