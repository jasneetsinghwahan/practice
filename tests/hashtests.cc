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
TEST(canConstruct_test, isitworking){
    myhash t;
    string ranSomNote{"aa"};
    string magazine{"aab"};
    bool exp = true;
    bool rst = t.canConstruct(ranSomNote,magazine);

    EXPECT_EQ(rst,exp);
}
TEST(isPathCrossing_test, isitworking){
    myhash t;
    string i{"NESWW"};
    bool exp = true;
    bool rst = t.isPathCrossing(i);

    EXPECT_EQ(rst,exp);
}
TEST(findLucky_test, isitworking){
    myhash t;
    vector<int> i{2,2,3,4};
    int exp = 2;
    int rst = t.findLucky(i);

    EXPECT_EQ(rst,exp);
}
TEST(frequencySort_test, isitworking){
    myhash t;
    string i{"Aabb"};
    string exp = "bbaA";
    string rst = t.frequencySort(i);

    EXPECT_THAT(rst,::testing::HasSubstr(exp));
}
TEST(numSubarraysWithSum_test, isitworking){
    myhash t;
    vector<int> i = {1,0,1,0,1};
    int goal = 2;
    int exp = 4;
    int rst = t.numSubarraysWithSum(i,goal);

    EXPECT_EQ(rst, exp);
}
TEST(numSubarraysWithSum_test, secondest){
    myhash t;
    vector<int> i = {0,0,0,0,0};
    int goal = 0;
    int exp = 15;
    int rst = t.numSubarraysWithSum(i,goal);

    EXPECT_EQ(rst, exp);
}
TEST(maximumUniqueSubarray_test, isitworking){
    myhash t;
    vector<int> i = {4,2,4,5,6};
    int exp = 17;
    int rst = t.maximumUniqueSubarray(i);

    EXPECT_EQ(rst, exp);
}
TEST(maximumUniqueSubarray_test, secondtest){
    myhash t;
    vector<int> i = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
    int exp = 16911;
    int rst = t.maximumUniqueSubarray(i);

    EXPECT_EQ(rst, exp);
}
TEST(checkInclusion_test, firsttest){
    myhash t;
    string s1 = "ab";
    string s2 = "eidboaoo";

    bool exp = false;
    bool rst = t.checkInclusion(s1, s2);

    EXPECT_EQ(rst, exp);
}
TEST(checkInclusion_test, secondtest){
    myhash t;
    string s1 = "adc";
    string s2 = "dcda";

    bool exp = true;
    bool rst = t.checkInclusion(s1, s2);

    EXPECT_EQ(rst, exp);
}
TEST(checkInclusion_test, thirdtest){
    myhash t;
    string s1 = "abc";
    string s2 = "ccccbbbbaaaa";

    bool exp = false;
    bool rst = t.checkInclusion(s1, s2);

    EXPECT_EQ(rst, exp);
}