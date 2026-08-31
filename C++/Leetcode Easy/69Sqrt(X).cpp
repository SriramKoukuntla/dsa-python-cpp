class Solution {
public:
    int mySqrt(int x) {
        int l = 0; 
        int r = x;
        int res = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            unsigned long long sq = (unsigned long long)m * m;
            if (sq == x) return m;
            else if (sq < x) {
                res = m;
                l = m+1;
            }
            else if (sq > x) {
                r = m-1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int l = 1; 
        int r = x/2;
        int res = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            unsigned long long sq = (unsigned long long)m * m;
            if (sq == x) return m;
            else if (sq < x) {
                res = m;
                l = m+1;
            }
            else if (sq > x) {
                r = m-1;
            }
        }
        return res;
    }
};

#include <algorithm>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x/2+1;
        int res = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (1LL * m * m > x) r = m-1;
            else {
                res = max(res, m);
                l = m + 1;
            }
        }
        return res;
    }
};