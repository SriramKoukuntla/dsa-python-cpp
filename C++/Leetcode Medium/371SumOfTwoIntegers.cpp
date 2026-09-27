#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            tuple<int, int> res = operation(a, b);
            a = get<0>(res);
            b = get<1>(res);
        }
        return a;
    }

    tuple<int, int> operation(int a, int b) {
        int res = a ^ b;
        int carry = a & b;
        carry <<= 1;
        return {res, carry};
    }
};