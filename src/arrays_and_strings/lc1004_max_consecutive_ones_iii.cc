#include <vector>
#include <string>
#include "mystrings.h"
using namespace std;

/***
 * leetcode 1004
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 * Example 1:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * Example 2:
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *  
 * Constraints:
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 * time cokmplexity is O(n) or 2.O(n) because right also traverse from 0th iindex to (k-1)th idex once and same for left index
*/

int 
mystrings::longestOnes(vector<int>& nums, int k) {
    int kctr = k, longest = 0, left = 0, right = 0, cur = 0, len = nums.size();
    while (right < len){
        if(nums[right] == 0 && kctr > 0){
            kctr--;
            right++;
            cur++;
        }
        else if(nums[right] == 0){
            longest = (longest < cur)? cur : longest;
            while(nums[left] != 0){
                left ++;
                cur--;
            }
            left++;
            right++;
        }
        else if (nums[right] == 1){
            cur++;
            right++;
        }
    }
    longest = (longest < cur)? cur : longest;
    return longest;
}
