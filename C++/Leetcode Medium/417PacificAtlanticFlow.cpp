#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> visitedPA(heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> visitedAT(heights.size(), vector<bool>(heights[0].size()));

        for (int i = 0; i < heights.size(); ++i) {
            helper(visitedPA, heights, i, 0, -1);
            helper(visitedAT, heights, i, heights[0].size()-1, -1);
        }
        for (int j = 0; j < heights[0].size(); ++j) {
            helper(visitedPA, heights, 0, j, -1);
            helper(visitedAT, heights, heights.size()-1, j, -1);
        }
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (visitedPA[i][j] && visitedAT[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }

    void helper(vector<vector<bool>>& visited, vector<vector<int>>& heights, int i, int j, int prevH) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) return;
        if (visited[i][j] == true || heights[i][j] < prevH) return;
        visited[i][j] = true;
        helper(visited, heights, i+1, j, heights[i][j]);
        helper(visited, heights, i-1, j, heights[i][j]);
        helper(visited, heights, i, j+1, heights[i][j]);
        helper(visited, heights, i, j-1, heights[i][j]);
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> PV(heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> AV(heights.size(), vector<bool>(heights[0].size()));
        for (int i = 0; i < heights.size(); ++i){
            helper(i, 0, PV, heights, -1);
            helper(i, heights[0].size()-1, AV, heights, -1);
        }
        for (int i = 0; i < heights[0].size(); ++i){
            helper(0, i, PV, heights, -1);
            helper(heights.size()-1, i, AV, heights, -1);
        }
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); ++i){
            for (int j = 0; j < heights[0].size(); ++j){
                if (PV[i][j] && AV[i][j]) res.push_back({i, j});
            }
        }
        return res; 
    }

    void helper(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights, int prevH){
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() 
        || visited[i][j] || heights[i][j] < prevH) return;
        visited[i][j] = true;
        helper(i+1, j, visited, heights, heights[i][j]);
        helper(i-1, j, visited, heights, heights[i][j]);
        helper(i, j+1, visited, heights, heights[i][j]);
        helper(i, j-1, visited, heights, heights[i][j]);
    }
};