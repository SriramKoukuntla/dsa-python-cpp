#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mem;
    int tribonacci(int n) {
        if (n < 2) return n;
        mem = vector<int>(n+1, -1);
        mem[0] = 0;
        mem[1] = 1;
        mem[2] = 1;
        return helper(n);
    }
    int helper(int n) {
        if (mem[n] != -1) return mem[n];
        mem[n] = helper(n-1) + helper(n-2) + helper(n-3);
        return mem[n];
    }
};

class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        vector<int> tab(n+1, 0);
        tab[1] = 1;
        tab[2] = 1;
        for (int i = 3; i < n+1; ++i) tab[i] = tab[i-1] + tab[i-2] + tab[i-3];
        return tab.back();
    }
};