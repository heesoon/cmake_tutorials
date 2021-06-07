#include <gtest/gtest.h>

// https://google.github.io/googletest/

int sum(int a, int b)
{
	return a+b;
}

TEST(BasicMathFunctionTest, IntSumFucTest)
{
	EXPECT_EQ(2, sum(1, 1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}