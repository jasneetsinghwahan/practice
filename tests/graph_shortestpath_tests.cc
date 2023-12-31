#include "src/search/search.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;


TEST(searchtest, try1){
    Search s;

    std::vector<int> vec = {2,3,4,5,6};
    int rst = s.BinarySearchRecursive(vec, 4);
    std::cout << "result: " << rst << std::endl;
}