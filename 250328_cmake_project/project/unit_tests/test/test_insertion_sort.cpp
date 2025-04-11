#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sortings.hpp"

TEST(ArraysEqual, InsertionSort) {
	int current[] = {5, 2, 9, 1, 5, 6, 22, 31, 22, 3};
	int current_size = sizeof(current) / sizeof(current[0]);
	dka::sort::insertion_sort(current, current_size);

	int expected[] = {1, 2, 3, 5, 5, 6, 9, 22, 22, 31};
	int expected_size = sizeof(expected) / sizeof(expected[0]);

	ASSERT_EQ(expected_size, current_size)
		<< "Different sizes of arrays";

	for (int i = 0; i < current_size; i++) {
		ASSERT_EQ(expected[i], current[i])
			<< "There is difference in element number "
			<< i;
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}