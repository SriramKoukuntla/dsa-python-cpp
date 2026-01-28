#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    vector<vector<bool>> visited;
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        visited = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<int> res;
        int i = 0;
        int j = 0;

        while (valid(i, j, matrix)){
            while (valid(i, j, matrix)) {
                res.push_back(matrix[i][j]);
                visited[i][j] = true;
                ++j;
            }
            --j;
            ++i;
            while (valid(i, j, matrix)) {
                res.push_back(matrix[i][j]);
                visited[i][j] = true;
                ++i;
            }
            --i;
            --j;
            while (valid(i, j, matrix)) {
                res.push_back(matrix[i][j]);
                visited[i][j] = true;
                --j;
            }
            ++j;
            --i;
            while (valid(i, j, matrix)) {
                res.push_back(matrix[i][j]);
                visited[i][j] = true;
                --i;
            }
            ++i;
            ++j;
        }
        return res;
    }

    bool valid(int i, int j, vector<vector<int>>& m) {
        if (i < 0 || i >= m.size()) return false;
        if (j < 0 || j >= m[0].size()) return false;
        if (visited[i][j]) return false;
        return true;
    }
};