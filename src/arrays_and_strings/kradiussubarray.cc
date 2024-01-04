#include "mystrings.h"
#include <vector>

std::vector<int> 
mystrings::getAverages(std::vector<int>& nums, int k){
    size_t len = nums.size();
    std::vector<int> rst(nums.size(), -1);
    if (2*k+1 > len)
        return rst;

    std::vector<int> post(nums.size());

    post[len-1] = nums[len-1];
    for (int i = len-2; i >= 0; i--)
        post[i] = nums[i] + post[i+1];
    
    
    size_t i = 0;
    int acc = 0;
    while (i < len){
        acc += nums[i];
        if(k <= i && i+k <= (len-1)){
            int totalsum = (k != 0)? (acc + post[i+1] - post[i+k] + nums[i+k]) : acc ;
            rst[i] = totalsum/(2*k+1);
            acc -= nums[i-k];
        }
        else {
            rst[i] = -1;
        }
        i++;
    }
    return rst;
}
