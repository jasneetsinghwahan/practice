#include "lrucache.h"
#include <math.h>
#include <cstdint> // uint64_t
#include <iostream>

/***
 * references: 
 * // https://people.computing.clemson.edu/~mark/464/p_lru.txt
 * // https://github.com/Tony080/TreePLRU/tree/master
*/

size_t 
treepseudoLRUCache::fillcnt(void){
    return count_;
}

/****
 * fetch the block in a set if available
 * incorrect in the sense that normally a word in a block is fetched and not the block
*/
bool
treepseudoLRUCache::get(int key){
    if (hashset_.count(key) == 0){
        return false;
    }
    else {
        updbitvec_();   // update the plru only if HIT
        return true;
    }
}

void
treepseudoLRUCache::put(int key, int value){
    // if NWAY_ has space, then fill it
    std::cout << "put: before: bvec_ \n" << bvec_ << std::endl;
    if (count_ < NWAY_){
        if (hashset_.count(key) == 0){
            hashset_.insert(key);      
            count_++;
            // call a function to tell the waynum
            size_t waynum = getwaynum();
            // insert the key into the array at the waynum
            idxkeymaparr_[waynum] = key;
        }
        updbitvec_();
    }
    else {  // if NWAY_ is full
        // if key is not present in current block, repace the block pointed to by plru
        if (hashset_.count(key) == 0){
            // get the current waynum
            size_t waynum = getwaynum();
            // access the array to get the key present at the waynum
            int prevkey = idxkeymaparr_[waynum];
            // replace the key in the hashset with the new key
            hashset_.erase(prevkey);
            // update the waynum index in array with the new key
            idxkeymaparr_[waynum] = key;
            // add the key in hashset_
            hashset_.insert(key);
            // update the bvec_
            updbitvec_();
        }
        else { // key is present
            // update the bvec_
            updbitvec_();
        }
    } 
    std::cout << "put: after: bvec_ \n" << bvec_ << std::endl;
}

/***
 * get waynum to store in the array, 
 * in practice: this is require to know which block to fetch in a set
*/
size_t
treepseudoLRUCache::getwaynum(void){
    size_t curidx = 0, previdx = 0, curlevel = 0;
    size_t maxlevel = log2(NWAY_);
    size_t rst = 0;
    while(curlevel < maxlevel){
        uint64_t curmask = 0;
        curmask |= 1 << ((NWAY_-1) - 1 - curidx); 
        bool curval = curmask & bvec_;
        if (curval == 0){
            curidx = 2 * curlevel + 1;
        } else {
            curidx = 2 * curlevel + 2;
            rst += 1;
        }
        curlevel++;
        rst *= 2;
    }
    return rst/2;   // /2 becasue, it generated results for the next level otherwise
}

/***
 * update plru one elevel at a time i.e. level0, level1..
 * insight: only one bit is flipped at a parrticular level
 * flips one level at a time, among the given level
*/
void
treepseudoLRUCache::updbitvec_(void){
    size_t curidx = 0, previdx = 0, curlevel = 0;
    size_t maxlevel = log2(NWAY_);
    while(curlevel < maxlevel){
        uint64_t curmask = 0;
        curmask |= 1 << ((NWAY_-1) - 1 - curidx); 
        bool curval = curmask & bvec_;
        previdx = curidx;
        if (curval == 0){
            curidx = 2 * curlevel + 1;
        } else {
            curidx = 2 * curlevel + 2;
        }
        appendvec_(curlevel, previdx, bvec_);
        curlevel++;
    }
}

// for a given level, flip the bit and preserve bits to the left and right of the bit
void
treepseudoLRUCache::appendvec_(size_t level, size_t modidx, uint64_t &updbvec){
    uint64_t mask = 0;
    uint64_t powof2 = pow(2,level);
    // overall mask
    uint64_t lptr = modidx - 1;
    if (modidx != 0){
        mask |= 1 << ((NWAY_-1) -1 - lptr); // there are NWAY_ -1 bits in total, but they begin from 0, so second -1
        mask -= 1; 
        mask = ~mask;
        mask = mask & updbvec;
    }
    // mask for RHS
    uint64_t rptr = modidx;
    uint64_t rmask = 0;
    rmask |= 1 << ((NWAY_-1) - 1 - rptr);
    rmask -= 1;
    rmask = rmask & updbvec;
    mask |= rmask;
    // extract the cur value at modidx
    uint64_t curmask = 0;
    curmask |= 1 << ((NWAY_-1) - 1 - modidx); 
    bool curval = curmask & updbvec;
    curval = !curval;
    mask |= curval << ((NWAY_-1) - 1 - modidx);
    updbvec = mask;
}