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