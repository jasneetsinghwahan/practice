#include "src/repetitions_cses.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(repetitionstest, isitworking){
    introductory_problems t;
    std::vector<char> ip = {'A','T','T','C','G','G','G','A'};
 
    EXPECT_EQ(t.repetitions(ip),3);
}