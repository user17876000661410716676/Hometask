#include <gtest/gtest.h>


#include "vector.hpp"

using biv::Vector;
TEST(VectorTest, Initialization) {
	Vector<int> vec;
	EXPECT_EQ(0, vec.get_size());
}

TEST(VectorTest, GetSize_PushBack) {
	Vector<int> vec;
	for (int i = 0; i < 41; i++) {
		vec.push_back(i);

		EXPECT_EQ(i + 1, vec.get_size());
		EXPECT_EQ(i, vec[i]);
	}
}

TEST(VectorTest, HasItem) {
	Vector<int> vec;
	std::size_t size = 15;

	EXPECT_FALSE(vec.has_item(0));

	for (int i = 0; i < size; i++) {
		vec.push_back(i);
	}

	EXPECT_FALSE(vec.has_item(16));
	EXPECT_FALSE(vec.has_item(-4));

	for (int i = 0; i < size; i++) {
		EXPECT_TRUE(vec.has_item(i));
	}
}

TEST(VectorTest, Insert) {
	Vector<int> vec;
	for (int i = 0; i < 30; i++) {
		vec.push_back(i);
	}
	
	EXPECT_FALSE(vec.insert(-1, 10));
	EXPECT_FALSE(vec.insert(233, 12));

	EXPECT_TRUE(vec.insert(15, -10));
	EXPECT_EQ(-10, vec[15]);
	EXPECT_EQ(31, vec.get_size());
	EXPECT_EQ(29, vec[30]);
}

TEST(VectorTest, RemoveFirst) {
	Vector<int> vec;
	for (int i = 0; i < 15; i++) {
		vec.push_back(i);
	}

	EXPECT_FALSE(vec.remove_first(15));
	EXPECT_FALSE(vec.remove_first(-1));

	EXPECT_TRUE(vec.remove_first(14));
	EXPECT_EQ(14, vec.get_size());

	EXPECT_TRUE(vec.remove_first(0));
	EXPECT_FALSE(vec[0] == 0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
