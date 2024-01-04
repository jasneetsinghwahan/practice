/**
* Approach using a hash table:
*
* Create an empty hash table to store elements and their indices.
* Iterate through the array from left to right.
* For each element nums[i], calculate the complement by subtracting it from the target: complement = target - nums[i].
* Check if the complement exists in the hash table. If it does, we have found a solution.
* If the complement does not exist in the hash table, add the current element nums[i] to the hash table with its index as the value.
* Repeat steps 3-5 until we find a solution or reach the end of the array.
* If no solution is found, return an empty array or an appropriate indicator.
* This approach has a time complexity of O(n) since hash table lookups take constant time on average. It allows us to solve the Two Sum problem efficiently by making just one pass through the array.
* source: https://leetcode.com/problems/two-sum/solutions/3619262/3-method-s-c-java-python-beginner-friendly/
*/

#include <unordered_map>
#include <vector>

class TwoSum {
    public:
    std::vector<int> twosumfunc(std::vector<int> &nums, int target);
};

std::vector<int>
TwoSum::twosumfunc(std::vector<int> &nums, int target){
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if(m.count(complement)){
            return {m[complement], i};
        }
        m[nums[i]] = i;
    }
    return {};
}