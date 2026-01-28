#include <vector>
using namesapce std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (helper(grid, i, j)) ++res;
            }
        }
        return res; 
    }

    bool helper(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        if (grid[i][j] == '0') return false;
        bool res = true;
        grid[i][j] = '0';
        res = helper(grid, i+1, j) || res;
        res = helper(grid, i-1, j) || res;
        res = helper(grid, i, j+1) || res;
        res = helper(grid, i, j-1) || res;
        return res;
    }
};