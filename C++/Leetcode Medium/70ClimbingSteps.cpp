#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n+1, 0);
        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i < mem.size(); ++i) mem[i] = mem[i-1] + mem[i-2];
        return mem[n];
    }
};