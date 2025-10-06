#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, 0));
        mem[0][0] = 1;
        for (int i = 0; i < mem.size(); ++i){
            for (int j = 0; j < mem[0].size(); ++j){
                if (i > 0) mem[i][j] += mem[i-1][j];
                if (j > 0) mem[i][j] += mem[i][j-1];
            }
        }
        return mem[m-1][n-1];
    }
};