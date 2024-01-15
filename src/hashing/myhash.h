#include <string>
#include <vector>
using namespace std;
class myhash{
    public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches);
    int maximumSum(vector<int>& nums);
    bool canConstruct(string ransomNote, string magazine);
    bool isPathCrossing(string path);
    int findLucky(vector<int>& arr);
    string frequencySort(string s);
    int numSubarraysWithSum_1stapproach(vector<int>& nums, int goal);      // working, tested and passed
    int numSubarraysWithSum(vector<int>& nums, int goal);
    int maximumUniqueSubarray(vector<int>& nums);
    bool checkInclusion(string s1, string s2);
};