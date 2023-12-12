#include <vector>
#include <iostream>
class introductory_problems {
    public:
    int repetitions(std::vector<char> list);
};

/***
 * You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
* Input
* The only input line contains a string of n characters.
* Output
* Print one integer: the length of the longest repetition.
* Constraints
* 1 \le n \le 10^6
* Example
* Input:
* ATTCGGGA
* Output:
* 3
*/
int
introductory_problems::repetitions(std::vector<char> list){
    if (list.empty())
        return 0;
    std::size_t count = 1;
    std::size_t maxlen = 0;
    char prevchar = list[0];
    for (std::size_t i = 1; i < list.size(); i++){
        if(list[i] == prevchar)
            count++;
        else {
            if (maxlen < count)
                maxlen = count;
            prevchar = list[i];
            count = 1;
        }
    }
    return maxlen;
}

int main(){
    introductory_problems t;
    std::vector<char> ip = {'A','T','T','C','G','G','G','A'};
 
    std::size_t rst = t.repetitions(ip);
    std::cout << rst  << std::endl;
}