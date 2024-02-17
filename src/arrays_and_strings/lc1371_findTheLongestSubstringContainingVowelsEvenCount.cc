#include "mystrings.h"
# include <vector>
#include <map>
#include <string>

int 
mystrings::findTheLongestSubstring(std::string s) {
    int pattern = 0;
    int rptr = 0;
    int cur = 0, max = 0;
    std::map<int, int> m;
    m[0] = -1;
    size_t len = s.size();
    while(rptr < len){
        if(s[rptr] == 'a' || s[rptr] == 'e' || s[rptr] == 'i' || s[rptr] == 'o' || s[rptr] == 'u') {
            int mask = 1 << (int)(s[rptr]-'a');
            pattern = pattern ^ mask;
        }
        if(m.count(pattern)){
            cur = rptr - m[pattern];
            max = (max < cur) ? cur : max;
        }
        else
            m[pattern] = rptr;
        rptr++;
    }
    return max; 
}
