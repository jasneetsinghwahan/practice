/***
 * Caches with various replacement policies
 * TODO: benchmark both these to see which runs faster
*/

#include <unordered_map>
#include <unordered_set>
#include <stddef.h>     // size_t
#include <vector>
#include <algorithm>    // std::fill
#include <cstdint> // uint64_t


/***
 * Fully associative cache with LRU replacement policy
*/
// modified from: https://www.enjoyalgorithms.com/blog/implement-least-recently-used-cache
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
/***
 * Fully associative cache with Tree-based pseudo LRU replacement policy
*/

class treepseudoLRUCache {
    private:
    std::unordered_set<int> hashset_;   // used to return O(1) for block lookup
    std::vector<int> idxkeymaparr_; // maps way# to the array idx, used to point the key to be replaced in hashset_ 
    uint64_t bvec_; // tree-pseudo LRU
    size_t NWAY_;
    size_t count_;    // keeps count of filled-up
    void updbitvec_(void);
    void appendvec_(size_t level, size_t idx, uint64_t &updbevc_);
    size_t getwaynum(void);

    public:
    treepseudoLRUCache(int NWAY){ // constructor
        NWAY_ = NWAY;
        count_ = 0; 
        bvec_ = 0;
        idxkeymaparr_.resize(NWAY);
    };

    bool get(int);
    void put(int key, int value);
    size_t fillcnt(void);
};