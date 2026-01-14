#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                res = max(res, helper(i, j, grid));
            }
        }
        return res;
    }
    int helper(int i, int j, vector<vector<int>>& grid){
        if (i < 0 || i >= grid.size()) return 0;
        if (j < 0 || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;
        int res = 0;
        ++res;
        grid[i][j] = 0;
        res += helper(i-1, j, grid); 
        res += helper(i, j-1, grid); 
        res += helper(i+1, j, grid); 
        res += helper(i, j+1, grid); 
        return res;
    }
};