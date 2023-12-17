#include <vector>
#include <string>
#include "mystrings.h"

using namespace std;

/***
 * TAGS: arrays, prefix sum, easy
 * 1991. Find the Middle Index in Array
 * Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).
 * 
 * A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].
 * 
 * If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.
 * 
 * Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.
 * time complexity: O(n)
 * space complexity: O(n)
*/

/***
 * approach: 
 * makes two arrays left_arr and right_arr which stores the cumulatiove sum from left-to-right and from right-to-left respectively
 * compare tehse two arrays and if at any index, the value matches, we found the middleindex 
*/
int 
mystrings::findMiddleIndex(std::vector<int>& nums) {
        
    size_t numslen = nums.size(); 
    // construct left cum. array
    vector<int> larr(nums.size()+1,0);
    for (int i = 1; i < (numslen+1); i++)
        larr[i] = larr[i-1] + nums[i-1];
    
    // construct right cum. array
    vector<int> rarr(nums.size()+1,0);
    int t = numslen-1;
    for (int i = 1; i < numslen; i++)
        rarr[i] = rarr[i-1] + nums[t--];
    
    int i = 1, j = numslen;
    while(i < numslen+1){
        if (larr[i] == rarr[j])
            return i-1;
        i++;
        j--;
    }
    return -1;
}

#include <numeric>
/***
 * time complexity: O(n)
 * space compliexty O(1)
 * intuition: instead of using arrays, it's like a two-pointer approach
 * wherein, rsum successively removes an element from the left-side and checks teh result with the lsum that also doesn't includes that element, in a w ay, that the removed element from rsum  is potential candidate for middleindex
*/
int 
mystrings::findMiddleIndex_alt(std::vector<int>& nums) {
    size_t numslen = nums.size(); 
    int rsum = std::accumulate(nums.begin(), nums.end(),0); // 0 indicates ints, 0.0 indicates float
    int i = 0, lsum = 0;
    while(i < numslen){
        rsum -= nums[i];
        if (lsum == rsum) return i;
        lsum += nums[i];
        i++;
    }
    return -1;
}
