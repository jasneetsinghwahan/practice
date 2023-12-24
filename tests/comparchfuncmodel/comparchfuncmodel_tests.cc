#include "src/comparchfuncmodel/lrucache.h"

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

TEST(cachetest, isitworking){
    LRUCache c(4);

    c.put(5,5);
    c.put(3,3);
    c.put(1,1);
    c.put(2,2);
    size_t rst = c.fillcnt();
    EXPECT_EQ(rst,4);
    c.put(6,6);
    rst = c.fillcnt();
    EXPECT_EQ(rst,4);

}

TEST(pseudocachetest, chkputwoevict){
    treepseudoLRUCache t(4);

    t.put(5,5);
    t.put(3,3);
    t.put(1,1);
    t.put(2,2);
    size_t rst = t.fillcnt();
    EXPECT_EQ(rst,4);

}
TEST(pseudocachetest, chkputwevict){
    treepseudoLRUCache t(4);

    t.put(5,5);
    t.put(3,3);
    t.put(1,1);
    t.put(2,2);
    t.put(6,6);
    bool rst = t.get(5);
    EXPECT_EQ(rst,false);
    rst = t.get(6);
    EXPECT_EQ(rst,true);
}

//TEST(findMiddleIndextest, firsttest){
//    mystrings t;
//    std::vector<int> s = {2,3,-1,8,4};
//    int exp = 3;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.findMiddleIndex(s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//    std::cout << "alternate" << std::endl;
//    start = chrono::high_resolution_clock::now();
//    rst = t.findMiddleIndex_alt(s);
//    stop = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//    std::cout << "2nd method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}
//
//TEST(findMiddleIndextest, secondtest){
//    mystrings t;
//    std::vector<int> s = {1,-1,4};
//    int exp = 2;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.findMiddleIndex(s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//    std::cout << "alternate" << std::endl;
//    start = chrono::high_resolution_clock::now();
//    rst = t.findMiddleIndex_alt(s);
//    stop = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//    std::cout << "2nd method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}
//
//TEST(flippinggametest, firsttest){
//    mystrings t;
//    std::vector<int> s = {1,0,0,1,0};
//    int exp = 4;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.flippinggame(s.size(), s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}
//TEST(flippinggametest, secondtest){
//    mystrings t;
//    std::vector<int> s = {1,0,0,1};
//    int exp = 4;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.flippinggame(s.size(), s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}
//
//TEST(waysToSplitArraytest, firsttest){
//    mystrings t;
//    std::vector<int> s = {10,4,-8,7};
//    int exp = 2;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.waysToSplitArray(s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}
//
//TEST(waysToSplitArraytest, secondtest){
//    mystrings t;
//    std::vector<int> s = {10,4,-8,7};
//    int exp = 2;
//    auto start = chrono::high_resolution_clock::now();
//    int rst = t.waysToSplitArray_alt(s);
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//    std::cout << "1st method time:" << duration.count() << std::endl;
//    EXPECT_EQ(rst,exp);
//}