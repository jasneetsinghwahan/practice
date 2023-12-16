#include <vector>
#include <string>
#include "mystrings.h"
using namespace std;
/***
 * 643. Maximum Average Subarray I
 * You are given an integer array nums consisting of n elements, and an integer k.
 * Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
 * Example 1:
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 * Example 2:
 * Input: nums = [5], k = 1
 * Output: 5.00000
 * time complexity is O(n) as the loop moves once across from 0th indice to highest indice
 * leetcode: easy
*/
double 
mystrings::findMaxAverage(vector<int>& nums, int k) {
    // build the first window
    double sum = 0;
    for (int i = 0; i < k; i++){
        sum += nums[i];
    }
    double rst = sum/k;
    size_t len = nums.size();
    // the window moves
    for (int head = k, tail = 0; head < len; head++, tail++){
        double t = (t*k - nums[tail] + nums[head])/k;
        if (t > rst) rst = t;
    }  
    return rst;      
}
