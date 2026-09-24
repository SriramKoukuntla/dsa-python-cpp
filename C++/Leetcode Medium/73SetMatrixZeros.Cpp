#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowsToTransformed;
        unordered_set<int> columnsToTransformed;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rowsToTransformed.insert(i);
                    columnsToTransformed.insert(j);
                } 
            }
        }
        for (int row : rowsToTransformed) {
            for (int i = 0; i < matrix[0].size(); ++i) matrix[row][i] = 0;
        }
        for (int col : columnsToTransformed) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][col] = 0;
        }
    }
};