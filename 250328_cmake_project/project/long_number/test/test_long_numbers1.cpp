#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "long_numbers.hpp"

using biv::LongNumber;

TEST(LongNumberTests, Equality) {
    LongNumber a("12345");
    LongNumber b("12345");
    LongNumber c("54321");
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_TRUE(a != c);
}

TEST(LongNumberTests, Comparison) {
    LongNumber a("123");
    LongNumber b("456");
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);
}

TEST(LongNumberTests, Sum) {
    LongNumber a("123");
    LongNumber b("456");
    LongNumber result = a + b;
    EXPECT_EQ(result, LongNumber("579"));
}

TEST(LongNumberTests, Difference) {
    LongNumber a("500");
    LongNumber b("123");
    LongNumber result = a - b;
    EXPECT_EQ(result, LongNumber("377"));
}

TEST(LongNumberTests, Multiplication) {
    LongNumber a("20");
    LongNumber b("5");
    LongNumber result = a * b;
    EXPECT_EQ(result, LongNumber("100"));
}

TEST(LongNumberTests, Division) {
    LongNumber a("100");
    LongNumber b("4");
    LongNumber result = a / b;
    EXPECT_EQ(result, LongNumber("25"));
}

TEST(LongNumberTests, Module) {
    LongNumber a("100");
    LongNumber b("7");
    LongNumber result = a % b;
    EXPECT_EQ(result, LongNumber("2"));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}