#include "mystrings.h"
#include <vector>

/***
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * solution copied from: https://leetcode.com/problems/product-of-array-except-self/
 * time complexity: O(n)
*/

std::vector<int> 
mystrings::productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> pre(n);
    std::vector<int> suff(n);
    pre[0] = 1;
    suff[n - 1] = 1;
    
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    for(int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] * nums[i + 1];
    }
    
    std::vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = pre[i] * suff[i];
    }
    return ans;
}