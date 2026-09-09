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