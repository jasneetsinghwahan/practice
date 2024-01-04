#include "src/arrays_and_strings/mystrings.h"

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

TEST(maximum_average_subarray, firsttest){
    mystrings t;
    std::vector<int> s = {0,4,0,3,2};
    int k = 1;
    
    std::cout << "test 1" << std::endl;
    EXPECT_EQ(t.findMaxAverage(s,k),4);
}

TEST(findMiddleIndextest, firsttest){
    mystrings t;
    std::vector<int> s = {2,3,-1,8,4};
    int exp = 3;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.findMiddleIndex(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
    std::cout << "alternate" << std::endl;
    start = chrono::high_resolution_clock::now();
    rst = t.findMiddleIndex_alt(s);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "2nd method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}

TEST(findMiddleIndextest, secondtest){
    mystrings t;
    std::vector<int> s = {1,-1,4};
    int exp = 2;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.findMiddleIndex(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
    std::cout << "alternate" << std::endl;
    start = chrono::high_resolution_clock::now();
    rst = t.findMiddleIndex_alt(s);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "2nd method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}

TEST(flippinggametest, firsttest){
    mystrings t;
    std::vector<int> s = {1,0,0,1,0};
    int exp = 4;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.flippinggame(s.size(), s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}
TEST(flippinggametest, secondtest){
    mystrings t;
    std::vector<int> s = {1,0,0,1};
    int exp = 4;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.flippinggame(s.size(), s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}

TEST(waysToSplitArraytest, firsttest){
    mystrings t;
    std::vector<int> s = {10,4,-8,7};
    int exp = 2;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.waysToSplitArray(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}

TEST(waysToSplitArraytest, secondtest){
    mystrings t;
    std::vector<int> s = {10,4,-8,7};
    int exp = 2;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.waysToSplitArray_alt(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}

TEST(product_of_array_except_self_test, firsttest){
    mystrings t;
    std::vector<int> s = {1,2,3,4};
    std::vector<int> exp = {24,12,8,6};
    auto start = chrono::high_resolution_clock::now();
    std::vector<int> rst = t.productExceptSelf(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_THAT(rst,::testing::ElementsAreArray(exp));
}

TEST(product_of_array_except_self_test, secondtest){
    mystrings t;
    std::vector<int> s = {-1,1,0,-3,3};
    std::vector<int> exp = {0,0,9,0,0};
    auto start = chrono::high_resolution_clock::now();
    std::vector<int> rst = t.productExceptSelf(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "2nd method time:" << duration.count() << std::endl;
    EXPECT_THAT(rst,::testing::ElementsAreArray(exp));
}

TEST(number_of_sub_array_with_odd_sum_test, firsttest_firstmethod){
    mystrings t;
    std::vector<int> s = {1,3,5};
    int exp = 4;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.numOfSubarrays_1stmethod(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}
TEST(number_of_sub_array_with_odd_sum_test, firsttest_secondmethod){
    mystrings t;
    std::vector<int> s = {1,3,5};
    int exp = 4;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.numOfSubarrays_2ndmethod(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst,exp);
}
TEST(getAverages_test, firsttest){
    mystrings t;
    std::vector<int> s = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    std::vector<int> exp = {-1,-1,-1,5,4,4,-1,-1,-1};
    auto start = chrono::high_resolution_clock::now();
    std::vector<int> rst = t.getAverages(s,k);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_THAT(rst,::testing::ElementsAreArray(exp));
}
TEST(getAverages_test, secondtest){
    mystrings t;
    std::vector<int> s = {10000};
    int k = 0;
    std::vector<int> exp = {10000};
    auto start = chrono::high_resolution_clock::now();
    std::vector<int> rst = t.getAverages(s,k);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_THAT(rst,::testing::ElementsAreArray(exp));
}
TEST(numSubarrayProductLessThanK_test, firsttest){
    mystrings t;
    std::vector<int> s = {10,5,2,6};
    int k = 100;
    int exp = 8;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.numSubarrayProductLessThanK(s,k);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst, exp);
}
TEST(numSubarrayProductLessThanK_test, secondtest){
    mystrings t;
    std::vector<int> s = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    int k = 19;
    int exp = 18;
    auto start = chrono::high_resolution_clock::now();
    int rst = t.numSubarrayProductLessThanK(s,k);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_EQ(rst, exp);
}
TEST(reverseWords_test, firsttest){
    mystrings t;
    std::string s{"Let's take LeetCode contest"};
    int k = 19;
    std::string exp{"s'teL ekat edoCteeL tsetnoc"};
    auto start = chrono::high_resolution_clock::now();
    std::string rst = t.reverseWords(s);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    std::cout << "1st method time:" << duration.count() << std::endl;
    EXPECT_THAT(rst, ::testing::StrEq(exp));
}