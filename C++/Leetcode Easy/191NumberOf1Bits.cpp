class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            n &= n-1;
            ++res;
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            if (n & 1 == 1) ++res;
            n = n >> 1;
        }
        return res; 
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            if (n & 1 == 1) ++res;
            n = n >> 1;
        }
        return res; 
    }
};