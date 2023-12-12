#include "src/arrays_and_strings/mystrings.h"

#include <vector>
#include <string>
#include <iostream>

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

TEST(maxconsecutiveonestest, firsttest){
    mystrings t;
    std::vector<int> s = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    
    std::cout << "test 1" << std::endl;
    EXPECT_EQ(t.longestOnes(s,k),6);
    s = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    k = 3;
    std::cout << "test 2" << std::endl;
    EXPECT_EQ(t.longestOnes(s,k),10);
}