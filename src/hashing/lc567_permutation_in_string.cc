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
myhash::checkInclusion(string s1, string s2) {
    // store the s1 string chars into a 'maps1', a map because, s1 charaters can have repititions, so we need to store the frequencies as well and also record the length and also maintain sum of all chars of s1
    unordered_map<char, int> dic, copy_dic;
    size_t i = 0, j = 0, lens1 = s1.size(), lens2 = s2.size(), sum  = 0, copy_sum;
    while(i < lens1){
        dic[s1[i]]++;
        sum += s1[i]-'a'+1;
        i++;
    }
    // traverse the loop of s2
    i = 0;
    copy_dic = dic;
    copy_sum = sum;
    while(i < lens2){
        // at the given indice, the first time a char matches with s1's char, check if the copy_maps1 value field > 0, if yes, then decrement, the value field and also decrement copy_sum
        if(copy_dic.find(s2[i]) != copy_dic.end()){
            if(copy_dic[s2[i]] > 0){
                copy_dic[s2[i]]--;
                copy_sum -= s2[i]-'a' + 1;
                if (copy_sum == 0) // if sum == 0, return true;
                    return true;
                i++;
            }
            else {
                // even if char is part of copy_maps1, but its value field is zero, then restart copy_maps1 from here: potential for flaw
                while(s2[j] != s2[i] && j <= i){
                    if (copy_dic[s2[j]] < dic[s2[j]]) {
                        copy_dic[s2[j]]++;
                        copy_sum += s2[j]-'a' + 1;
                    }
                    else;
                    j++;
                }
                j++;
                i++;
            }
        } 
        else {
            // if a char comes that is not part of copy_s1 and copy_sum != sum, then restart
            if (copy_sum != sum){
                copy_sum = sum;
                copy_dic = dic;
            }
            i++;
        }
    }
    return false;        
}

