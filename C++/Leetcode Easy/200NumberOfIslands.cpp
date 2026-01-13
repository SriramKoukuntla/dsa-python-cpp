#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == '0') continue;
                ++res;
                helper(i, j, grid);
            }
        }
        return res;
    }
    void helper (int i, int j, vector<vector<char>>& grid){
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        helper (i-1, j, grid);
        helper (i+1, j, grid);
        helper (i, j-1, grid);
        helper (i, j+1, grid);
    }
};