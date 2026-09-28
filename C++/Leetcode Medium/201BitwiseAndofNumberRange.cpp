#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 1;
        for (int i = 0; i < 31; ++i) mask <<= 1;
        
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int bitL = left & mask;
            int bitR = right & mask;
            if (bitL != bitR) break;
            res |= bitL;
            mask >>= 1;
        }
        return res;


    }
};