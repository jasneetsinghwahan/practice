#include "bit_twiddling.h"
int 
bittwiddles::min_max(int x, int y){
    int r;
    r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // min(x, y)
    return r;
}