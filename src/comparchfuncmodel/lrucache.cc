#include "lrucache.h"

int
LRUCache::get (int key){

    if (m_.count(key) > 0){
        node *element = m_[key];
        element->prev->next = element->next;
        element->next->prev = element->prev;
        element->next = head_->next;
        head_->next->prev = element;
        element->prev = head_;
        head_->next = element;
        return element->value;
    }
    return -1;
}

void
LRUCache::put(int key, int value){
    // only update if the element exists
    if (m_.count(key) > 0){
        node *element = m_[key];
        element->value = value;
        element->prev->next = element->next;
        element->next->prev = element->prev;
        element->next = head_->next;
        head_->next->prev = element;
        element->prev = head_;
        head_->next = element;
    }
    else {
        node *newelement = new node;
        newelement->value = value;
        newelement->next = head_->next;
        head_->next->prev = newelement;
        newelement->prev = head_;
        head_->next = newelement;
        count_++;
        if (count_ > capacity_){
            // remove the last element
            node *remelement = tail_->prev;
            remelement->prev->next = tail_;
            tail_->prev = remelement->prev;
            delete remelement;
            count_--;
        }
    }
}

size_t
LRUCache::fillcnt(void){
    return count_;
}