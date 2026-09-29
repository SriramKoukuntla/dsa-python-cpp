#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int, unordered_map<bool, int>> cache;
        return dfs(cache, prices, 0, false);
    }

    int dfs(unordered_map<int, unordered_map<bool, int>>& cache, vector<int>& prices, int index, bool mode) { //false for buy, true for sell
        if (index >= prices.size()) return 0;
        if (cache.find(index) != cache.end() && cache[index].find(mode) != cache[index].end()) return cache[index][mode];
        int skipRes = dfs(cache, prices, index+1, mode);
        int actionRes = (mode == false) 
                        ? dfs(cache, prices, index+1, true) - prices[index]
                        : dfs(cache, prices, index+2 , false) + prices[index];
        int finalRes = max({skipRes, actionRes});
        cache[index][mode] = finalRes;
        return finalRes;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for (int i = 1; i < prices.size(); ++i){
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;
            hold = max(prevHold, prevRest-prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sold, hold);
    }
};  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mem(prices.size() + 2, 0);
        mem[prices.size()-1] = 0;
        for(int i = prices.size()-1; i >= 0; --i){
            int maxProfit = mem[i+1];
            for (int j = i+1; j < prices.size(); ++j){
                // cout << prices[j]-prices[i] << endl;
                maxProfit = max(maxProfit, prices[j]-prices[i] + mem[j+2]);
            }
            mem[i] = maxProfit;
        }
        return mem[0];
    }
};