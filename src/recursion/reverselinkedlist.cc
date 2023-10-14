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

/**
 * 1. find the middle of the linked list
 * 2. make the last element of the initial half point to null element
 * 3. reverse the second-half of the list
 * 4. compare the first-half with reverse second-half
 * 5/ helper function added so taht memory leakage could be resolved
*/
bool 
Solution::isPalindrome(ListNode *head){
    ListNode *revhead = nullptr;
    bool rst = isPalindrome_aux(head, revhead);

    while (revhead != nullptr){
        ListNode *newhead = revhead->next;
        delete revhead;
        revhead = newhead;
    }
    return rst;
}
bool 
Solution::isPalindrome_aux(ListNode* head, ListNode* &revhead){
    if (!head || !head->next) return head;
    ListNode* slow = head; ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
    }
    ListNode* start = slow->next;
    slow->next = nullptr;
    ListNode *sechead = reverseList(start);
    revhead = sechead;
    while (sechead) {
        if (head->val != sechead->val) return false;
        head = head->next;
        sechead = sechead->next;
    }
    return true;
}
