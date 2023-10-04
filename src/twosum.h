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