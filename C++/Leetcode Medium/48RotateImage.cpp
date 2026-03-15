#include <vector>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>>& matrix, int l, int r, int u, int d) {
        if (r <= l) return; // base case

        vector<int> temp;
        int numIterations = r-l;

        for (int i = 0; i < numIterations; ++i) temp.push_back(matrix[u][l+i]); //Grabbing top values
        for (int i = 0; i < numIterations; ++i) swap(temp[i], matrix[u+i][r]); //Swapping right values for top values
        for (int i = 0; i < numIterations; ++i) swap(temp[i], matrix[d][r-i]); //Swapping down values for right values
        for (int i = 0; i < numIterations; ++i) swap(temp[i], matrix[d-i][l]); //Swapping left values for down values
        for (int i = 0; i < numIterations; ++i) swap(temp[i], matrix[u][l+i]); //Swapping up values for left values

        helper(matrix, l+1, r-1, u+1, d-1);
    }


    void rotate(vector<vector<int>>& matrix) {
        helper(matrix, 0, matrix.size()-1, 0, matrix.size()-1);
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()/2; ++i){
            for (int j = 0; j < matrix.size()/2; ++j){
                int topLeft = matrix[i][j];
                int topRight = matrix[j][matrix.size()-1-i];
                int bottomRight = matrix[matrix.size()-1-i][matrix.size()-1-j];
                int bottomLeft = matrix[matrix.size()-1-j][i];

                matrix[j][matrix.size()-1-i] = topLeft;
                matrix[matrix.size()-1-i][matrix.size()-1-j] = topRight;
                matrix[matrix.size()-1-j][i] = bottomRight;
                matrix[i][j] = bottomLeft;
            }
        }
        if (matrix.size() % 2 == 1){
            for (int i = 0; i < matrix.size()/2; ++i){
                int up = matrix[i][matrix.size()/2];
                int right = matrix[matrix.size()/2][matrix.size()-1-i];
                int down = matrix[matrix.size()-1-i][matrix.size()/2];
                int left = matrix[matrix.size()/2][i];

                matrix[matrix.size()/2][matrix.size()-1-i] = up;
                matrix[matrix.size()-1-i][matrix.size()/2] = right;
                matrix[matrix.size()/2][i] = down;
                matrix[i][matrix.size()/2] = left;
                
            }
        }
    }
};