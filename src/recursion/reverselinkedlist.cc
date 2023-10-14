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

bool 
Solution::isPalindrome(ListNode* head){
    ListNode* nxtmatch = nullptr;
    isPalindrome_aux(head, nxtmatch);
    if (nxtmatch != nullptr)
        return false;
    else
        return true;
}

void
Solution::isPalindrome_aux(ListNode* head, ListNode* &nxtmatch){
    // base case
    if (head == nullptr || head->next==nullptr){
        nxtmatch = nullptr;
        return;
    }

    ListNode *rhshead = head->next;
    // essentially traverse the list and also return teh next element to be matched
    isPalindrome_aux(rhshead, nxtmatch);

    if (head->val == rhshead->val)
        return;
    else if (nxtmatch != nullptr){
        if (head->val == nxtmatch->val){
            if(nxtmatch->next != nullptr)
                nxtmatch = nxtmatch->next;
            else {
                nxtmatch = nullptr;
            }
        }
        else
            nxtmatch = rhshead;
    }
    else
        nxtmatch = rhshead;

}