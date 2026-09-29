#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<int, unordered_map<int, int>> cache;
        return dfs(cache, coins, amount, 0);
    }

    int dfs(unordered_map<int, unordered_map<int, int>>& cache, vector<int>& coins, int amount, int index) {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (index == coins.size()) return 0;
        if (cache[amount].find(index) != cache[amount].end()) return cache[amount][index];
        int skip = dfs(cache, coins, amount, index+1);
        int partake = dfs(cache, coins, amount-coins[index], index);
        int res = skip + partake;
        cache[amount][index] = res;
        return res; 
    }
};

#include <vector>
#include <algorithm>
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        sort(coins.begin(), coins.end());
        while (coins.size() > 0 && coins[coins.size()-1] > amount) coins.pop_back();

        //rows represent "coins"
        //columns represent amounts
        vector<vector<unsigned long long>> mem(coins.size(), vector<unsigned long long>(amount+1));

        for (int i = 0; i < coins.size(); ++i){mem[i][0] = 1;}

        for (int i = 0; i < mem.size(); ++i){
            for (int j = 1; j < mem[0].size(); ++j){
                if (j-coins[i] >= 0) mem[i][j] += mem[i][j-coins[i]];
                if (i > 0) mem[i][j] += mem[i-1][j];
            }
        }
        return static_cast<int>(mem[mem.size()-1][mem[0].size()-1]);
    }
};