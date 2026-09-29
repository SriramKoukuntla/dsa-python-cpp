#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        unordered_map<int, unordered_map<int, int>> cache;
        return dfs(cache, s, t, 0, 0);
    }

    int dfs(unordered_map<int, unordered_map<int, int>>& cache, string& s, string& t, int sI, int tI) {
        if (tI == t.size()) return 1;
        if (sI == s.size()) return 0;
        if (cache[sI].find(tI) != cache[sI].end()) return cache[sI][tI];

        int res;
        if (s[sI] != t[tI]) res = dfs(cache, s, t, sI+1, tI);
        else {
            int skip = dfs(cache, s, t, sI+1, tI);
            int use = dfs(cache, s, t, sI+1, tI+1);
            res = skip + use;
        }
        cache[sI][tI] = res;
        return res; 
    }
};
//sI, tI, 