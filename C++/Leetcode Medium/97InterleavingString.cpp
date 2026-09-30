#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_map<int, unordered_map<int, int>> cache;
        return dfs(cache, s1, s2, s3, 0, 0);
    }

    bool dfs(unordered_map<int, unordered_map<int, int>>& cache, 
            string& s1, string& s2, string& s3, int s1Index, int s2Index) {
        int s3Index = s1Index + s2Index;
        if (s3Index == s3.size()) return true;
        if (cache[s1Index].find(s2Index) != cache[s1Index].end()) return cache[s1Index][s2Index];
        bool useS1 = (s1Index >= s1.size()) ? false :
                (s1[s1Index] == s3[s3Index]) && dfs(cache, s1, s2, s3, s1Index+1, s2Index);
        bool useS2 = (s2Index >= s2.size()) ? false :
                (s2[s2Index] == s3[s3Index]) && dfs(cache, s1, s2, s3, s1Index, s2Index+1);
        bool res = useS1 || useS2;
        cache[s1Index][s2Index] = res;
        return res; 
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<bool> tab(s2.size()+1, false);
        tab[0]= true;        
        for (int i = 1; i < tab.size(); ++i) {
            int s2Index = i-1;
            int s3Index = i-1;
            tab[i] = (tab[i-1]) & (s2[s2Index] == s3[s3Index]);
        }
    
        for (int i = 0; i < s1.size(); ++i) {
            int s1Index = i;
            int s3Index = i;
            tab[0] = (tab[0]) & (s1[s1Index] == s3[s3Index]);
            for (int j = 1; j < tab.size(); ++j) {
                int s2Index = j-1;
                s3Index = s1Index + s2Index + 1;
                tab[j] = ((tab[j-1]) & (s2[s2Index] == s3[s3Index]) | 
                         ((tab[j]) & (s1[s1Index] == s3[s3Index])));
            }
        }

        return tab.back();
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> tab(s1.size()+1, vector<bool>(s2.size()+1, false));
        tab[0][0] = true;        
        for (int i = 1; i <= s1.size(); ++i) {
            int s3Index = i-1;
            int s1Index = i-1;
            tab[i][0] = (tab[i-1][0]) & (s1[s1Index] == s3[s3Index]);
        }
        for (int i = 1; i <= s2.size(); ++i) {
            int s3Index = -1 + i;
            int s2Index = i-1;
            tab[0][i] = (tab[0][i-1]) & (s2[s2Index] == s3[s3Index]);
        }
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                int s1Index = i-1;
                int s2Index = j-1;
                int s3Index = j+i-1;
                tab[i][j] = 
                    ((tab[i-1][j]) & (s1[s1Index] == s3[s3Index])) | 
                    ((tab[i][j-1]) & (s2[s2Index] == s3[s3Index]));
            }
        }
        return tab.back().back();
    }
};

#include <unordered_map>
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //dfs with a cache
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_map<string, bool> cache;
        return dfs(s1, 0, s2, 0, s3, 0, cache);
    }
private:
    bool dfs(string& s1, int idx1, string& s2, int idx2, string& s3, int idx3, unordered_map<string, bool>& cache){
        if (idx1 == s1.size() && idx2 == s2.size() && idx3 == s3.size()) return true;
        string key = s1.substr(idx1) + string("|") + s2.substr(idx2) + string("|") + s3.substr(idx3);
        if (cache.find(key) != cache.end()) return cache[key];

        bool left = false; bool right = false;
        if (idx1 < s1.size() && s1[idx1] == s3[idx3]) left = dfs(s1, idx1+1, s2, idx2, s3, idx3+1, cache);
        if (left) {
            cache[key] = true;
            return true;
        }
        if (idx2 < s2.size() && s2[idx2] == s3[idx3]) right = dfs(s1, idx1, s2, idx2+1, s3, idx3+1, cache);
        cache[key] = right;
        return right;
    }
};