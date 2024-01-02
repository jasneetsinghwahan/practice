#include <string>
#include <vector>

class mystrings{
    public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words);
    int longestOnes(std::vector<int>& nums, int k);
    double findMaxAverage(std::vector<int>& nums, int k);
    int findMiddleIndex(std::vector<int>& nums);
    int findMiddleIndex_alt(std::vector<int>& nums);
    int flippinggame(int k, std::vector<int> nums);
    int waysToSplitArray(std::vector<int>& nums);
    int waysToSplitArray_alt(std::vector<int>& nums);
    std::vector<int> productExceptSelf(std::vector<int>& nums);
    int numOfSubarrays_1stmethod(std::vector<int>& arr);
    int numOfSubarrays_2ndmethod(std::vector<int>& arr);
};