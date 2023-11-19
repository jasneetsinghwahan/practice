#include "src/missingnumber.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(missingnumtest, isitworking){
    missingnumber w;
    int num = 3;
    std::vector<int> nums = {1,3};
    int rst = w.missingnum(num,nums);
    EXPECT_EQ(rst, 2);

}

TEST(missingnumbertest, twoisitworking){
    missingnumber w;
    int num = 5;
    std::vector<int> nums = {1,2,5};
    std::vector<int> rst = w.two_missingnum(num,nums);
    std::vector<int> expres = {3,4};
    EXPECT_THAT(rst, UnorderedElementsAreArray(expres));
}

TEST(missingnumbertest, threeisitworking){
    missingnumber w;
    int num = 7;
    std::vector<int> nums = {0,2,5,6};
    std::vector<int> rst = w.three_missingnum(num,nums);
    std::vector<int> expres = {1,3,4};
    EXPECT_THAT(rst, UnorderedElementsAreArray(expres));
}

TEST(missingnumbertest, nisitworking){
    missingnumber w;
    int num = 9;
    std::vector<int> nums = {9,5,6,2};
    std::vector<int> rst = w.nmissingnum(nums);
    std::vector<int> expres = {3,4,7,8};
    EXPECT_THAT(rst, UnorderedElementsAreArray(expres));
}