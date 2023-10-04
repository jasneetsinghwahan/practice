#include "src/tree.h"

#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(tree, isitworking){
    Tree t;
    t.CreateSampleTree2();
    t.InOrder(t.returnroot());
    int kthidx = 2;
    std::cout << kthidx << "th smallest element is: " << t.kthsmallestelement(kthidx) << std::endl;
}