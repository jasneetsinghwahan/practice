#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

std::vector<std::vector<int>>
myhash::findWinners(std::vector<std::vector<int>>& matches){
    std::unordered_map<int, int> atleastonelose; 
    std::unordered_set<int> seen;
    // every team seen on the winnder's side is added to 'seen'
    for (auto &match: matches){
        seen.insert(match[0]);
        atleastonelose[match[1]]++;
    }
    // if any team present in seen is present in' atleastonelose', then remove it
    std::vector<std::vector<int>> rst(2);
    for (auto it = seen.begin(); it != seen.end(); it++){
        if(atleastonelose.find(*it) == atleastonelose.end())
            rst[0].push_back(*it);
    }

    for (auto [key, val]: atleastonelose){
        if(val == 1)
            rst[1].push_back(key);
    }
    std::sort(rst[0].begin(),rst[0].end() );
    std::sort(rst[1].begin(),rst[1].end() );
    return rst;
}