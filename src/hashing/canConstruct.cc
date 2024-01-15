#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
bool 
myhash::canConstruct(string ransomNote, string magazine) {
    // populate an array where index points to char in 'ransomNote' and frequency is captured in val
    size_t lenrs = ransomNote.size();
    size_t i = 0;
    vector<int> poprs(26,0);
    while(i < lenrs){
        poprs[ransomNote[i]-'a']++;
        i++;
    }
    i = 0;
    size_t lenm = magazine.size();
    while (i < lenm){
        poprs[magazine[i]-'a']--;
        i++;
    }
    for(i = 0; i < 26; i++)
        if(poprs[i] > 0)
            return false;
    return true;
    
}