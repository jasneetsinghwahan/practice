#include <vector>
#include <string>
#include "myhash.h"
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

/***
 * lc1394
*/
int 
myhash::findLucky(vector<int>& arr) {
    for (auto n : arr) {
        n &= 0xFFFF;
        if (n <= arr.size())
            arr[n - 1] += 0x10000;
    }
    for (auto i = arr.size(); i > 0; --i)
        if ((arr[i - 1] >> 16) == i)
            return i;
    return -1;
}