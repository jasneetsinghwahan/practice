#include "src/arrays_and_strings/mystrings.h"

#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(repetitionstest, isitworking){
    mystrings t;
    std::string s = "abcde";
    std::vector<std::string> words = {"a","bb","acd","ace"};
 
    EXPECT_EQ(t.numMatchingSubseq(s,words),3);
}