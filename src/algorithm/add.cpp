void Add(std::vector<std::vector<int>>& data) {
    for(size_t i=0; i<data.size(); ++i)
        for(size_t j=0; j<data[i].size(); ++i)
            data[i][j]+=1;
}
#include <gtest/gtest.h>
#include <vector>
#include "add.cpp" // Include the source file where the Add function is defined

TEST(AddTest, Test1) {
    std::vector<std::vector<int>> data = {{1, 2, 3}, {4, 5, 6}};
    Add(data);
    ASSERT_EQ(data[0][0], 2);
    ASSERT_EQ(data[0][1], 3);
    ASSERT_EQ(data[0][2], 4);
    ASSERT_EQ(data[1][0], 5);
    ASSERT_EQ(data[1][1], 6);
    ASSERT_EQ(data[1][2], 7);
}

TEST(AddTest, Test2) {
    std::vector<std::vector<int>> data;
    Add(data);
    ASSERT_TRUE(data.empty());
}

TEST(AddTest, Test3) {
    std::vector<std::vector<int>> data = {{-1, -2, -3}, {-4, -5, -6}};
    Add(data);
    ASSERT_EQ(data[0][0], 0);
    ASSERT_EQ(data[0][1], -1);
    ASSERT_EQ(data[0][2], -2);
    ASSERT_EQ(data[1][0], -3);
    ASSERT_EQ(data[1][1], -4);
    ASSERT_EQ(data[1][2], -5);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}