#include "src/weird_algo.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(weird_algotest, isitworking){
    weird_algo w;
    int num = 9;
    std::vector<int> actrst = w.weirdalgo(num);
    for (int i=0; i < actrst.size(); i++){
        std::cout << actrst[i] << "\t";
    }
    std::cout<< std::endl;
}