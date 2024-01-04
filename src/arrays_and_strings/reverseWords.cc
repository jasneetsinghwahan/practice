#include "mystrings.h"
#include <vector>
#include <string>
#include <stack>

/***
 * Problem: 
 * Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Example 2:
 * Input: s = "Mr Ding"
 * Output: "rM gniD"
 * Solution:
 * uses an intuition that adding a char to string costs O(n), where n is the length of new string, hence, instead, we add the chars into a vector and at the end
 * convert the vector of chars to string 
 * time complexity: O(n)
*/
std::string 
mystrings::reverseWords(std::string s){
    std::vector<char> t;
    std::stack<char> stack;
    
    size_t i = 0, len = s.size();
    while(i < len){
        // traverse and keep adding
        char k = s[i];
        if(k != ' '){
            stack.push(s[i]);
        }
        else {
            while (!stack.empty()) {
                t.push_back(stack.top());
                stack.pop();
            }
            if (k == ' ')
                t.push_back(k); 
        }
        i++;
    }
    if (!stack.empty())
        while (!stack.empty()) {
            t.push_back(stack.top());
            stack.pop();
        }

    std::string rst(t.begin(), t.end());
    return rst;
}
