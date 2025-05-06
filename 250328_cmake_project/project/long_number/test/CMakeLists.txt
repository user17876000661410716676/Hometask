set(SOURCES
	test_long_numbers2.cpp
)

add_executable(test_long_numbers2 ${SOURCES})
target_link_libraries(test_long_numbers2
	gtest_main
	gmock_main
	long_numbers_lib
)

add_test(test_long_numbers2 test_long_numbers2)
