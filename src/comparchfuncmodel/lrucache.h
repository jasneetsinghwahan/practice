/***
 * Fully associative cache with LRU replacement policy
*/

#include <unordered_map>
#include <stddef.h>     // size_t


// copied from: https://www.enjoyalgorithms.com/blog/implement-least-recently-used-cache

class LRUCache {
    private:
    struct node {
        int key;
        int value;
        node *prev;
        node *next;
    };
    std::unordered_map<int, node *> m_;
    size_t capacity_;
    size_t count_;    // keeps count of filled-up
    node *head_;
    node *tail_;
    public:
    LRUCache(int capacity){ // constructor
        capacity_ = capacity;
        head_ = new node;
        head_->prev = nullptr;
        tail_ = new node;
        tail_->next = nullptr;
        head_->next = tail_;
        tail_->prev = head_;
        count_ = 0; 
    };

    int get(int);
    void put(int key, int value);
    size_t fillcnt(void);
    ~LRUCache(){
        while(head_->next != tail_){
            node *curelement = head_->next;
            head_->next = curelement->next;
            curelement->next->prev = head_;
            delete curelement;            
        }
        delete head_;
        delete tail_;
    };
};



