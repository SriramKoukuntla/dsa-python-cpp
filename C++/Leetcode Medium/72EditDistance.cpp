//DFS DP Solution Using 2D Vector over Hashmap
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return dfs(0, 0, word1, word2, dp);
    }
private:
    int dfs(int idx1, int idx2, string& word1, string& word2, vector<vector<int>>& dp){
        if (word2.size() == idx2) return word1.size() - idx1;
        if (word1.size() == idx1) return word2.size() - idx2;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (word1[idx1] == word2[idx2]){
            int res = dfs(idx1+1, idx2+1, word1, word2, dp);
            dp[idx1][idx2] = res;
            return res;
        }
        int insert = 1 + dfs(idx1, idx2+1, word1, word2, dp);
        int del = 1 + dfs(idx1+1, idx2, word1, word2, dp);
        int replace = 1 + dfs(idx1+1, idx2+1, word1, word2, dp);
        int res = min(min(insert, del), replace);
        dp[idx1][idx2] = res;
        return res;
    }
};

//DFS Caching
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        unordered_map<string, int> cache;
        return dfs(word1, word2, cache);
    }
private:
    int dfs(string word1, string word2, unordered_map<string, int>& cache){
        string key = word1 + "|" + word2;
        if (cache.find(key) != cache.end()) return cache[key];
        if (word2.size() == 0) return word1.size();
        if (word1.size() == 0) return word2.size();
        if (word1[0] == word2[0]) return dfs(word1.substr(1), word2.substr(1), cache);
        int insert = 1 + dfs(word1, word2.substr(1), cache);
        int del = 1 + dfs(word1.substr(1), word2, cache);
        int replace = 1 + dfs(word1.substr(1), word2.substr(1), cache);
        int res = min(min(insert, del), replace);
        cache[key] = res;
        return res;
    }
};

//DFS Caching with pass by references for strings
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        unordered_map<string, int> cache;
        return dfs(0, 0, word1, word2, cache);
    }
private:
    int dfs(int idx1, int idx2, string& word1, string& word2, unordered_map<string, int>& cache){
        string key = word1.substr(idx1) + "|" + word2.substr(idx2);
        if (cache.find(key) != cache.end()) return cache[key];
        if (word2.size() == idx2) return word1.size() - idx1;
        if (word1.size() == idx1) return word2.size() - idx2;
        if (word1[idx1] == word2[idx2]){
            int res = dfs(idx1+1, idx2+1, word1, word2, cache);
            cache[key] = res;
            return res;
        }
        int insert = 1 + dfs(idx1, idx2+1, word1, word2, cache);
        int del = 1 + dfs(idx1+1, idx2, word1, word2, cache);
        int replace = 1 + dfs(idx1+1, idx2+1, word1, word2, cache);
        int res = min(min(insert, del), replace);
        cache[key] = res;
        return res;
    }
};