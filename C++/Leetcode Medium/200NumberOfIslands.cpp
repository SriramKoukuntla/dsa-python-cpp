#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    bool helper(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return false;
        grid[i][j] = '0';
        helper(grid, i-1, j);
        helper(grid, i+1, j);
        helper(grid, i, j-1);
        helper(grid, i, j+1);
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (helper(grid, i, j)) ++res;
            }
        }
        return res;
    }
};

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