#include <iostream>
#include <vector> 
#include <assert.h>

class weird_algo {
    public:
        std::vector<int> weirdalgo(int n);
};

std::vector<int>
weird_algo::weirdalgo(int n){
    assert(n > 1);
    std::vector<int> rst;
    rst.push_back(n);
    while (n != 1){
        if(n%2 == 0)
            n = n/2;
        else
            n = 3*n + 1;
        rst.push_back(n);
    }
    return rst;
}