#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> tab(s.size()+1, vector<unsigned long long>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) tab[i].back() = 1;

        for (int sI = s.size()-1; sI >= 0; --sI) {
            for (int tI = t.size()-1; tI >= 0; --tI) {
                tab[sI][tI] = tab[sI+1][tI];
                if (s[sI] == t[tI]) tab[sI][tI] += tab[sI+1][tI+1];
            }
        }
        return tab.front().front();
    }
};
//state, sI, tI

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