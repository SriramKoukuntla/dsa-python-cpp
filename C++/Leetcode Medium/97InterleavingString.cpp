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