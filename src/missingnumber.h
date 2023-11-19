/***
 *  https://cses.fi/problemset/task/1083/
 */ 

#include <iostream>
#include <vector> 
#include <assert.h>
#include <algorithm>
#include <unordered_set>

class missingnumber {
    public:
        int missingnum(int n, std::vector<int> nums);
        std::vector<int> two_missingnum(int, std::vector<int>);
        std::vector<int> three_missingnum(int, std::vector<int>);
        std::vector<int> nmissingnum(std::vector<int>);
};


int 
missingnumber::missingnum(int n, std::vector<int> nums){
    int xorr = 0;
    for(int i = 0; i < nums.size(); i++){
        xorr = xorr ^ nums[i];
    }
    int refr = 0;
    for (int i = 1; i < n+1; i++)
        refr = refr ^ i;
    return refr ^ xorr;
}

/***
*Asymptotic complexity in terms of size of the given array \`n\`:
* Time: O(n).
* Auxiliary space: O(1).
* Total space: O(n).
* properties of xor:
*   xor all the given numbers and also xor all the numbers in the range
*   if only one number is missing, then that's the result
*   if two numbers are missing, then, 
*       first find the set bit in the xor'ed result, this bit identifies one of the two missing numbers
*       now, xor with given numbers and the entire range
*       you have the first result
*       now xor this result with original xor
*       you have the second result
*/
std::vector<int> 
missingnumber::two_missingnum(int n, std::vector<int> nums) {
    int xorr = 0;
    // xoring all integers of array arr
    for(int i : nums) {
        xorr ^= i;
    }
    //xoring all integers from 1 to n
    for(int i = 1; i <= n; i++) {
        xorr ^= i;
    }
    //now xor contains the value of the xor of 2 missing numbers
    //we find a setBit in this resultant xor
    int setBit = 0;
    for(int i = 0; i < 32; i++) {
        setBit = 1 << i;
        if((xorr & setBit) != 0) {
            break;
        }
    }
    //we xor all integers having the corresponding bit set
    int xor2 = 0;
    for(int i = 1; i <= n; i++) {
        if((i & setBit) != 0) {
            xor2 ^= i;
        }
    }
    //we xor all integers having the corresponding bit set in arr
    for(int i : nums) {
        if((i & setBit) != 0) {
            xor2 ^= i;
        }
    }
    //the resultant xor gives us one of the numbers
    //we obtain the second number using this first number
    int num1 = xor2, num2 = xorr^num1;
    if(num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    std::vector<int> result;
    result.push_back(num1);
    result.push_back(num2);
    return result;
}

std::vector<int> 
missingnumber::three_missingnum(int n, std::vector<int> nums){
    int xorr = 0;
    // xor with all the given numbers
    for (int i = 0; i < nums.size(); i++)
        xorr = xorr ^ nums[i];
    // xor with all the numbers in the range
    for (int i = 1; i < n; i++)
        xorr = xorr ^ i;        // xorr now has the results of xor of the three missing numbers
    // find the index of 1st bit
    int setbit = 0;
    for (int i = 0; i < 32; i++){
        setbit = 1 << i;
        if(xorr & setbit)
            break;
    }
    int xor2 = 0;
    // xor with all the given numbers whose setbit = 1
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] & setbit)
            xor2 = xor2 ^ nums[i];
    }
    // xor with all the numbers in the range n whose setbit = 1
    for (int i = 1; i < n; i++){
        if(i & setbit)
            xor2 = xor2 ^ i;
    }
    // voila!! we have found our first number
    std::vector<int> rst;
    rst.push_back(xor2);
    // find the 2nd setbit
    int setbit2 = 0;
    bool firsttime = false;
    for (int i = 0; i < 32; i++){
        setbit2 = 1 << i;
        if(xorr & setbit2)
            if(!firsttime) {
                firsttime = true;
                continue;
            }
            else
                break;
    }
    xor2 = 0;
    // xor with all the given numbers whose setbit = 1
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] & setbit2)
            xor2 = xor2 ^ nums[i];
    }
    // xor with all the numbers in the range n whose setbit = 1
    for (int i = 1; i < n; i++){
        if(i & setbit2)
            xor2 = xor2 ^ i;
    }
    // voila!! we have found our 2nd number
    rst.push_back(xor2);
    // 3rd number is xor of 2nd number, 1st number and original xor
    rst.push_back(rst[0] ^ rst[1] ^ xorr);
    return rst;
}

/***
 * find k missing numbers in the given numbers
 * approach: 
 *  sort the given numbers
 *  define a hash set
 *  insert all integers beginning from lowest given number to highest given number
 *  remove all the given numbers from the hash set
 *  convert the hashset into vectors and return  
 *  source: https://stackoverflow.com/questions/53823608/find-out-n-numbers-of-missing-elements-from-an-array-in-java
*/
std::vector<int> 
missingnumber::nmissingnum(std::vector<int> nums){
    std::sort(nums.begin(), nums.end());
    std::unordered_set<int> us;
    for (int i = nums[0]; i < nums[nums.size()-1]; i++)
        us.insert(i);
    std::vector<int> rst;
    for (int i = 0; i < nums.size(); i++)
        if(us.count(nums[i]))
            us.erase(nums[i]);
    std::unordered_set<int>::iterator it = us.begin();
    while(it != us.end()){
        rst.push_back(*it);
        it++;
    }
    return rst;
}