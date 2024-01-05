#include "src/hashing/myhash.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(findWinners_test, isitworking){
    myhash t;
    std::vector<std::vector<int>> s = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    std::vector<std::vector<int>> exp = {{1,2,10}, {4,5,7,8}};
    std::vector<std::vector<int>> rst = t.findWinners(s);

    EXPECT_THAT(rst,::testing::ElementsAreArray(exp));
}
TEST(maximumSum_test, isitworking){
    myhash t;
    std::vector<int> i = {18,43,36,13,7};
    int exp = 54;
    int rst = t.maximumSum(i);

    EXPECT_EQ(rst,exp);
}