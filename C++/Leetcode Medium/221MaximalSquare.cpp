#include <vector>
using namespace std;
class Solution {
public:
    int helper(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& mem) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return 0;
        if (matrix[i][j] == '0') return 0;
        if (mem[i][j] != -1) return mem[i][j];

        int temp1 = min(helper(matrix, i-1, j, mem), helper(matrix, i, j-1, mem));
        int temp2 = min(temp1, helper(matrix, i-1, j-1, mem));
        int res = temp2 + 1;
        
        mem[i][j] = res;
        return res;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, helper(matrix, i, j, mem));
            }
        }
        return res* res;
    }
};