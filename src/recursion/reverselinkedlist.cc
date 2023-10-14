#include "reverselinkedlist.h"
/*
* leetcode problem no. 206 titled Reverse linkd list
*/
ListNode * 
Solution::reverseList(ListNode *head){
    // base case
    if (head == nullptr || head->next == nullptr)
        return head;

    head->next  = reverseList(head->next);

    ListNode *newhead = head->next;
    ListNode *onemorehead = head->next;
    while (onemorehead->next != nullptr) onemorehead = onemorehead->next;
    onemorehead->next = head;
    head->next = nullptr;
    head = newhead; 
    return head;
}