#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mem;
    int minCostClimbingStairs(vector<int>& cost) {
        mem = vector<int>(cost.size(), -1);
        mem[cost.size()-1] = cost[cost.size()-1];
        mem[cost.size()-2] = cost[cost.size()-2];
        helper(cost, 0);
        return min(mem[0], mem[1]);
    }
    int helper(vector<int>& cost, int i) {
        if (mem[i] != -1) return mem[i];
        int res = cost[i] + min(helper(cost, i+1), helper(cost, i+2));
        mem[i] = res;
        return res;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> tab(cost.size(), 0);
        tab[tab.size()-1] = cost[cost.size()-1];
        tab[tab.size()-2] = cost[cost.size()-2];

        for (int i = tab.size()-3; i >= 0; --i) tab[i] = cost[i] + min(tab[i+1], tab[i+2]);
        return min(tab[0], tab[1]);
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); ++i){
            cost[i] = min(cost[i-2], cost[i-1]) + cost[i];
        }
        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
};