#include "src/comparchfuncmodel/lrucache.h"
#include "src/comparchfuncmodel/arith.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;

#include <cassert>
#include <cstdint>
#include <climits>
#include <cstddef>
#include <type_traits>

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

TEST(arithtest, firsttest){
    arith t;
    uint64_t a = (1ULL << 32) + (1ULL << 51);   // 2251804108652544
    uint64_t b = (1ULL << 18) + (1ULL << 60);   // 1152921504607109120

    uint64_t rst = t.mulhu(a,b); // 1125899906842624
    uint64_t exp = 1125899906842624;
    EXPECT_EQ(rst,exp);
}