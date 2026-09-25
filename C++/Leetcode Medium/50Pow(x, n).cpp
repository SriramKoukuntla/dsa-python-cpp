#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double val = helper(x, abs((long)n));
        return n < 0 ? 1/val : val;
    }

    double helper(double x, long n) { 
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n % 2 == 1) {
            return x * helper(x*x, n/2);
        }
        else return helper(x*x, n/2);
    }
};