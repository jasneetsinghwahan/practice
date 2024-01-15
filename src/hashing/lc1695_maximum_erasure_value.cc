#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
// works only if nums[i] is between 0 and 31
int 
myhash::maximumUniqueSubarray(vector<int>& nums) {
    size_t len  = nums.size(), rptr = 0, lptr= 0, score  = 0, psum = 0;
    unordered_set<int> seen;
    while(rptr < len){
        if(seen.count(nums[rptr]) > 0){
            score = (score < psum) ? psum : score;
            while(nums[lptr] != nums[rptr]){
                psum -= nums[lptr];
                seen.erase(nums[lptr]);
                lptr++;
            }
            lptr++;
        }
        else{
            psum += nums[rptr];
            seen.insert(nums[rptr]);
        }
        rptr++; 
    }
    score = (score < psum) ? psum : score;
    return score;
}