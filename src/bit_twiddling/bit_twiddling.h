#include <string>
#include <vector>
const unsigned CHAR_BIT=8;

class bittwiddles{
    public:
    int min_max(int, int);
};

class missingnumber {
    public:
        int missingnum(int n, std::vector<int> nums);
        std::vector<int> two_missingnum(int, std::vector<int>);
        std::vector<int> three_missingnum(int, std::vector<int>);
        std::vector<int> nmissingnum(std::vector<int>);
};