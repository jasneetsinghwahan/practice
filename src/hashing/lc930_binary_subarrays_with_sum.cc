#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int 
myhash::numSubarraysWithSum_1stapproach(vector<int>& nums, int goal) {
    size_t rptr = 0, len  = nums.size();
    int cur = 0, count = 0;
    unordered_map<int, int> dic;
    dic[0] = 1;
    while(rptr < len){
        cur += nums[rptr];
        if (cur < goal){
            dic[cur]++;
        }
        else {
            count += dic[cur-goal];
            dic[cur]++;
        }
        rptr++;            
    } 
    return count;
}

int atMost(vector<int> &nums, int goal);

int 
myhash::numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
int atMost(vector<int> &A, int S){
    if (S < 0) return 0;
    int res = 0, i = 0, n = A.size();
    for (int j = 0; j < n; j++) {
        S -= A[j];
        while (S < 0)
            S += A[i++];
        res += j - i + 1;
    }
    return res;
}