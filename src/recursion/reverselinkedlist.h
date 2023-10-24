/**
/* Definition for singly-linked list.
/* struct ListNode {
/*     int val;
/*     ListNode *next;
/*     ListNode() : val(0), next(nullptr) {}
/*     ListNode(int x) : val(x), next(nullptr) {}
/*     ListNode(int x, ListNode *next) : val(x), next(next) {}
/* };*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *reverseList(ListNode * head);
        bool isPalindrome(ListNode* head);
        ListNode* removeElements(ListNode *, int val);

    private:
    bool isPalindrome_aux(ListNode* head, ListNode* &revhead);
};