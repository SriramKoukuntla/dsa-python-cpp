#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    int leftB = 0; int upB = 0;
    int rightB; int downB;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        rightB = matrix[0].size();
        downB = matrix.size();

        vector<int> res;
        int i = 0; int j = 0;
        while (valid(i, j)){
            while (valid(i, j)) res.push_back(matrix[i][j++]);
            --j; ++i; ++upB;
            while (valid(i, j)) res.push_back(matrix[i++][j]);
            --i; --j; --rightB;
            while (valid(i, j)) res.push_back(matrix[i][j--]);
            ++j; --i; --downB;
            while (valid(i, j)) res.push_back(matrix[i--][j]);
            ++i; ++j; ++leftB;
        }
        return res;
    }

    bool valid(int i, int j) {
        if (i < upB || i >= downB) return false;
        if (j < leftB || j >= rightB) return false;
        return true;
    }
};

#include <vector>
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