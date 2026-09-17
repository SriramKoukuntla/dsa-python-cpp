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