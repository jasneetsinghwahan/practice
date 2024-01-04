#include "mystrings.h"
#include <vector>

int 
mystrings::numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    int runprod = 1;
    size_t len = nums.size();
    size_t rst = 0;
    size_t rptr = 0, lptr = 0;
    while (rptr < len){
        runprod *= nums[rptr];
        if(runprod < k ){
            rst += (rptr-lptr+1);
        }
        else {
            while(runprod >= k){
                runprod = runprod/nums[lptr];
                lptr++;
            }
            rst += rptr-lptr+1;
        }
        rptr++;
    }
    return rst;      
}