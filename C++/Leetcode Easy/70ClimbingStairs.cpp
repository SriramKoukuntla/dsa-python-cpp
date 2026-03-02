#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int helper(int n, unordered_map<int, int>& mem) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (mem.find(n) != mem.end()) return mem[n];
        int res = helper(n-1, mem) + helper(n-2, mem);
        mem[n] = res;
        return res;
    }

    int climbStairs(int n) {
        unordered_map<int, int> mem;
        return helper(n, mem);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> tab(n); //index = stair-1;
        tab[0] = 1;
        tab[1] = 2;
        for (int i = 2; i < n; ++i) tab[i] = tab[i-1] + tab[i-2];
        return tab.back();
    }
};

#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem = {0, 1, 2};
        for (int i = 3; i < n+1; ++i){
            mem.push_back(mem[i-1] + mem[i-2]);
        }
        return mem[n];
    }
};