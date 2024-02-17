#include "mystrings.h"
#include <vector>
#include <limits.h>
#include <algorithm>

int 
mystrings::findMaxLength(std::vector<int>& nums) {
    std::vector<int> arr(2*nums.size() + 1, INT_MIN);
	arr[nums.size()] = -1;
    int maxLen = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 0 ? -1 : 1);
		if (arr[sum + nums.size()] >= -1)  maxLen = std::max(maxLen, i - arr[sum + nums.size()]);
		else  arr[sum + nums.size()] = i; 
    }
    return maxLen;
}
