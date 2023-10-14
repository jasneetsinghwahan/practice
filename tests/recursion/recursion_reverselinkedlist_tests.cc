#include "src/recursion/reverselinkedlist.h"

#include "gtest/gtest.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include <vector>
using ::testing::ElementsAreArray;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAreArray;
using ::testing::UnorderedElementsAre;

TEST(reverselinkedlist, threeelements){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    Solution solution;
    ListNode* rtnhead = solution.reverseList(head);
    ListNode* cpyhead = rtnhead;
    int i = 0;
    while (rtnhead != nullptr){
        std::cout << i << "th element is: " << rtnhead->val << std::endl;
        i++;
        rtnhead = rtnhead->next;
    }
    // delete the linked list
    while (cpyhead != nullptr){
        ListNode *newhead = cpyhead->next;
        delete cpyhead;
        cpyhead = newhead;
    }
}

TEST(reverselinkedlist, noelements){
    ListNode *head = new ListNode; 
    Solution solution;
    ListNode* rtnhead = solution.reverseList(head);
    ListNode* cpyhead = rtnhead;
    int i = 0;
    while (rtnhead != nullptr){
        std::cout << i << "th element is: " << rtnhead->val << std::endl;
        i++;
        rtnhead = rtnhead->next;
    }
    // delete the linked list
    while (cpyhead != nullptr){
        ListNode *newhead = cpyhead->next;
        delete cpyhead;
        cpyhead = newhead;
    }
}

TEST(reverselinkedlist, twoelements){
    ListNode *head = new ListNode(1); 
    head->next = new ListNode(2); 
    Solution solution;
    ListNode* rtnhead = solution.reverseList(head);
    ListNode* cpyhead = rtnhead;
    int i = 0;
    while (rtnhead != nullptr){
        std::cout << i << "th element is: " << rtnhead->val << std::endl;
        i++;
        rtnhead = rtnhead->next;
    }
    // delete the linked list
    while (cpyhead != nullptr){
        ListNode *newhead = cpyhead->next;
        delete cpyhead;
        cpyhead = newhead;
    }
}