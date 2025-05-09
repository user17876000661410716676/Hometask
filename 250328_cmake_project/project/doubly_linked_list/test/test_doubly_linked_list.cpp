#include <gtest/gtest.h>


#include "doubly_linked_list.hpp"

using biv::DoublyLinkedList;

TEST(DoublyLinkedListTest, Initialization) {
	DoublyLinkedList<int> list;
	EXPECT_EQ(0, list.get_size());
}

TEST(DoublyLinkedListTest, GetSize_PushBack) {
	DoublyLinkedList<int> list;
	for (int i = 0; i < 30; i++) {
		list.push_back(i);
		EXPECT_EQ(i+1, list.get_size());
	}
}

TEST(DoublyLinkedListTest, HasItem) {
	DoublyLinkedList<int> list;
	for (std::size_t i = 0; i < 20; i++) {
		list.push_back(i);
	}

	EXPECT_TRUE(list.has_item(0));
	EXPECT_TRUE(list.has_item(10));
	EXPECT_TRUE(list.has_item(19));
	EXPECT_FALSE(list.has_item(21));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
	DoublyLinkedList<int> list;
	for (std::size_t i = 0; i < 20; i++) {
		list.push_back(i);
	}

	EXPECT_TRUE(list.remove_first(0));
	EXPECT_EQ(19, list.get_size());
	EXPECT_FALSE(list.remove_first(21));
	EXPECT_FALSE(list.has_item(0));
}

TEST(DoublyLinkedListTest, GetValue) {
	DoublyLinkedList<int> list;
	for (std::size_t i = 0; i < 20; i++) {
		list.push_back(i);
	}

	EXPECT_EQ(0, list.get_value(0));
	EXPECT_EQ(10, list.get_value(10));
	EXPECT_EQ(19, list.get_value(19));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}