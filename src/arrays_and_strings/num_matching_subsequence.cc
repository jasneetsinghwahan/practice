#include <vector>
#include <string>
#include "mystrings.h"
using namespace std;

/***
* lc792. Number of Matching Subsequences
* Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
* A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
* For example, "ace" is a subsequence of "abcde".
* 
* Example 1:
* Input: s = "abcde", words = ["a","bb","acd","ace"]
* Output: 3
* Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
*
* Example 2:
* Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
* Output: 2
*  
* Constraints:
* 1 <= s.length <= 5 * 104
* 1 <= words.length <= 5000
* 1 <= words[i].length <= 50
* s and words[i] consist of only lowercase English letters.
* source: https://leetcode.com/problems/number-of-matching-subsequences/
*/

/***
 * problem: instead of having O(n^2) time complexity, can we do it better
 * intuition: arrays are best for indexing operations and the input is english characters (small-case) such that a is '97' and z is '122' and furthermore, stings in c/c++ have last character as end-of-string
 * define a array of vector of pairs of size 128 because we need index [0] and indices [97] to [122]
 * pair.first points to the word id and pair.second points to the next character to be processed
 * add first char from each of the 'words' to this string as their respective ascii position
 * then, fetch first char from 'S' and index into the 'waiting', if the char doesn't exists in 'waiting', then fecth the next char from 's'
 * if the char exists, then transfer the same to local vector of pairs and 
 * if the a word has ended, i.e. its next char is '000' waiting[words[it.first][it.second++]].push_back(it), then, store it in waiting[0]
 * for instance, for words[0] = 'a', it = (0,1) and when we access words[it.first = 0][it.second = 1++] it points to `000` and we store the new it, where it.second = 2 to waiting[0] i.e. contents of waiting[0] is a vector of pairs, where first pair is (0,2)
 * else, (if the word hasn't ended)
 * we append appropriate position in waiting with the new pair
*/

int 
mystrings::numMatchingSubseq(string S, vector<string>& words) {
    vector<pair<int, int>> waiting[128];
    for (int i = 0; i < words.size(); i++)
        waiting[words[i][0]].emplace_back(i, 1);
    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[words[it.first][it.second++]].push_back(it);
    }
    return waiting[0].size();
}