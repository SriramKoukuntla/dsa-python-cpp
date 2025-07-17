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