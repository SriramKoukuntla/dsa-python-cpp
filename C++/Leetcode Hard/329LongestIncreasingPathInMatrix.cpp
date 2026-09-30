#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_map<int, int>> cache;
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int tempRes = dfs(cache, matrix, i, j);
                res = max(res, tempRes);
            }
        }
        return res;
    }
    int dfs(unordered_map<int, unordered_map<int, int>>& cache, vector<vector<int>>& matrix, int i, int j) {
        if (cache[i].find(j) != cache[i].end()) return cache[i][j];
        int goUp = (i != 0 && matrix[i-1][j] > matrix[i][j]) ? dfs(cache, matrix, i-1, j) : 0; 
        int goLeft = (j != 0 && matrix[i][j-1] > matrix[i][j]) ? dfs(cache, matrix, i, j-1) : 0;
        int goDown = (i != matrix.size()-1 && matrix[i+1][j] > matrix[i][j]) ? dfs(cache, matrix, i+1, j) : 0;
        int goRight = (j != matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]) ? dfs(cache, matrix, i, j+1) : 0;
        int res = max({goUp, goLeft, goDown, goRight}) + 1;
        cache[i][j] = res;
        return res;
    }
};