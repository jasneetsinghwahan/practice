#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int 
myhash::maximumSum(vector<int>& nums) {
    size_t len = nums.size(), i = 0;
    int max = -1;
    unordered_map<int, int> dic;
    while (i < len){
        // first extract all the digits of a given number and add them
        int curnum = nums[i];
        int rem = 0;
        while(curnum){
            rem += curnum%10;
            curnum = curnum/10;
        }
        if(dic.find(rem) != dic.end()){
            max = ((nums[dic[rem]] + nums[i]) > max) ? (nums[dic[rem]] + nums[i]) : max;
            if(nums[dic[rem]] < nums[i])
                dic[rem] = i;
        }
        else
            dic[rem] = i;
        i++;
    }
    return max;        
}