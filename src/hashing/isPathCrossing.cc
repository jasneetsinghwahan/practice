#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
bool 
myhash::isPathCrossing(string path) {
    set<pair<int, int>> seen = {{0,0}};
    size_t len = path.size(), i = 0;
    int ns = 0, ew = 0;
    while (i < len){
        
        if(path[i] == 'N')
            ns++;
        else if (path[i] == 'S')
            ns--;
        else if (path[i] == 'E')
            ew++;
        else
            ew--;
        pair<int, int> p(ns,ew);
        if (seen.find(p) != seen.end())
            return true;
        seen.insert(p);
        i++;
    }
    return false;
    
}