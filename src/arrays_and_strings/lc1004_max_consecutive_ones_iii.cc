#include <vector>
#include <string>
#include "mystrings.h"
using namespace std;

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
            //kctr++;
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
