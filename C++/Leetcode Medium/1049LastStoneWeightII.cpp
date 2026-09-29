#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_map<long long, int> cache;
        return dfs(cache, stones, 0, 0);
    }
    int dfs(unordered_map<long long, int>& cache, vector<int>& stones, int index, int res) {
        if (index == stones.size()) return res;
        long long key = ((long long)index << 32) + res;
        if (cache.find(key) != cache.end()) return cache[key];
        int addRes = dfs(cache, stones, index+1, res+stones[index]);
        int subtractRes = dfs(cache, stones, index+1, res-stones[index]);
        if (subtractRes < 0) subtractRes = INT_MAX;
        cache[key] = min(addRes, subtractRes);
        return cache[key];
    }
};