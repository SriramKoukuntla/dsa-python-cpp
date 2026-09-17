#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        mem[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        return helper(mem, obstacleGrid, mem.size()-1, mem[0].size()-1);
    }
    int helper(vector<vector<int>>& mem, vector<vector<int>>& obstacleGrid, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        if (obstacleGrid[i][j] == 1) return 0;
        int res = helper(mem, obstacleGrid, i-1, j) + helper(mem, obstacleGrid, i, j-1);
        mem[i][j] = res;
        return res; 
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> tab(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        if (obstacleGrid[0][0] != 1) tab[0][0] = 1;
        for (int i = 0; i < tab.size(); ++i) {
            for (int j = 0; j < tab[0].size(); ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] != 1) {
                    int left = i-1 >= 0 ? tab[i-1][j] : 0;
                    int top = j-1 >= 0 ? tab[i][j-1] : 0;
                    tab[i][j] = left + top;
                }
            }
        }
        return tab.back().back();
    }
};