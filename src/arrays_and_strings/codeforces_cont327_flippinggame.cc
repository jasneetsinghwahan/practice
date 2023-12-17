#include <vector>
#include <string>
#include "mystrings.h"

using namespace std;

/**
 * Iahub got bored, so he invented a game to be played on paper.
 * He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x.
 * 
 * The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.
 * 
 * Input
 * The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.
 * 
 * Output
 * Print an integer — the maximal number of 1s that can be obtained after exactly one move.
 * 
 * i/p: 5
 * 1 0 0 1 0
 * o/p: 4
 * 
 * i/p: 4
 * 1 0 0 1
 * o/p: 4
*/
int
mystrings::flippinggame(int k, std::vector<int> nums){
    // calculate the sum of 1's from left to right
    size_t len = nums.size();
    int rptr = 1, lptr = 0;
    // sliding window approach
    int curlen = 1, maxlen = INT32_MIN;
    while(rptr < len){
        // logic for increasing rptr
        if (nums[rptr] == 0){
            rptr++;
        }
        else {
            curlen = rptr - lptr + 1;
            if (maxlen < curlen) maxlen = curlen;
            lptr = rptr;
            rptr++;
        }
    }
    return maxlen;
}
