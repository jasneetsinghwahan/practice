#include "mystrings.h"
#include <vector>
/***
 * Given an array of integers arr, return the number of subarrays with an odd sum.
 * Since the answer can be very large, return it modulo 109 + 7.
 * 
 * Example 1:
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 * All sub-arrays sum are [1,4,9,3,8,5].
 * Odd sums are [1,9,3,5] so the answer is 4.
 * 
 * Example 2:
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 * All sub-arrays sum are [2,6,12,4,10,6].
 * All sub-arrays have even sum and the answer is 0.
 * 
 * Example 3:
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
*/
int 
mystrings::numOfSubarrays_1stmethod(std::vector<int>& arr) {
    size_t cnt = 0;
    size_t size = arr.size();
    std::vector<int> rst(size,0);
    size_t traverser = 0;
    rst[traverser] = arr[traverser];
    if (rst[traverser] % 2 != 0) cnt++;
    traverser++;
    while(traverser < size){
        rst[traverser] = rst[traverser-1] + arr[traverser];
        if (rst[traverser] % 2 != 0) cnt++;
        size_t subtraverser = 0;
        while(subtraverser < traverser){
            if((rst[traverser] - rst[subtraverser]) % 2 != 0)
                cnt++;
            subtraverser++;
        } 
        traverser++;
    }
    return cnt;           
    
}
/***
 * solution comes from an observation that if current sum is odd, then add number of even sub-arrays and if the current sum is even, add number of odd sub-arrays
 * furthermore, add 1 adiditonally oper iteration if current sum is odd
 * time complexity: O(n)
*/
int 
mystrings::numOfSubarrays_2ndmethod(std::vector<int>& arr) {
    size_t cnt = 0;
    size_t size = arr.size();
    size_t cntevens = 0, cntodds = 0;
    int rst = 0;
    size_t traverser = 0;
    rst = arr[traverser];
    if (rst % 2 != 0) {
        cnt++;
        cntodds++;
    }
    else
        cntevens++;
    traverser++;
    while(traverser < size){
        rst = rst + arr[traverser];
        if (rst % 2 != 0) {
            cnt++;
            cntodds++;
            cnt += cntevens;
        }
        else {
            cntevens++;
            cnt += cntodds;
        }
        traverser++;
    }
    return cnt;           
}