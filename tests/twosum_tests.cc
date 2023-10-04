#include "src/twosum.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(twosumtests, isitworking){
    TwoSum t;
    std::vector<int> nums = {1,5, 11, 19, 30, 45};
    int target = 35;
    std::vector<int> expres = {1,4};
    EXPECT_THAT(t.twosumfunc(nums, target),UnorderedElementsAreArray(expres));
}