class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1; //shift bits to insert next bit
            res += (n % 2);
            n /= 2;
        }
        return res; 
    }
};

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i){
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }
        return res;
    }
};