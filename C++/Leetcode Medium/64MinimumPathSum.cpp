#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> tab(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                long top = i-1 >= 0 ? tab[i-1][j] : INT_MAX;
                long left = j-1 >= 0 ? tab[i][j-1] : INT_MAX;

                int sum = (top == INT_MAX && left == INT_MAX) ? grid[i][j] : min(grid[i][j] + top, grid[i][j] + left);
                tab[i][j] = sum;
            }
        }
        return tab.back().back();
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        mem[0][0] = grid[0][0];
        return helper(grid, mem, grid.size()-1, grid[0].size()-1);   
    }
    int helper(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
        if (mem[i][j] != -1) return mem[i][j];
        int top = i-1 >= 0 ? helper(grid, mem, i-1, j) : INT_MAX;
        int left = j-1 >= 0 ? helper(grid, mem, i, j-1) : INT_MAX;
        int res = (top == INT_MAX && left == INT_MAX) ? grid[i][j] : grid[i][j] + min(top, left);
        mem[i][j] = res;
        return res;
    }
};