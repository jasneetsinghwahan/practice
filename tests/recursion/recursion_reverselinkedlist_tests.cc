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

TEST(isPalindrometest, fourlementspalindrome){
    ListNode *head = new ListNode(1);
    head = new ListNode(2, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(1);
    ListNode *delhead = head;
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, true);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}

TEST(isPalindrometest, twolementsnotpalindrome){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, false);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}

TEST(isPalindrometest, fourlementsnotpalindrome){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, false);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}

TEST(isPalindrometest, fivelementspalindrome){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, true);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}

TEST(isPalindrometest, longseqpalindrome){
    std::vector<int> vec = {8,0,7,1,7,7,9,7,5,2,9,1,7,3,7,0,6,5,1,7,7,9,3,8,1,5,7,7,8,4,0,9,3,7,3,4,5,7,4,8,8,5,8,9,8,5,8,8,4,7,5,4,3,7,3,9,0,4,8,7,7,5,1,8,3,9,7,7,1,5,6,0,7,3,7,1,9,2,5,7,9,7,7,1,7,0,8};
    ListNode *head;
    head = new ListNode(vec[0]);
    for (int i = 1; i < vec.size(); i++){
        head = new ListNode(vec[i], head);
    }
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, true);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}

TEST(isPalindrometest, longsevenseqpalin){
    std::vector<int> vec = {8,8,5,8,9,8,5,8,8};
    ListNode *head;
    head = new ListNode(vec[0]);
    for (int i = 1; i < vec.size(); i++){
        head = new ListNode(vec[i], head);
    }
    
    Solution solution;
    bool actrst = solution.isPalindrome(head);
    EXPECT_EQ(actrst, true);
    while (head != nullptr){
        ListNode *newhead = head->next;
        delete head;
        head = newhead;
    }
}