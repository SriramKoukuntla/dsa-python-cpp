#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0;
        int end = matrix.size() * matrix[0].size() - 1;
        int middle = (begin + end) / 2;
        while (begin <= end){
            int middle = (begin + end) / 2;
            int index1 = middle / matrix[0].size();
            int index2 = middle % matrix[0].size();
            int val = matrix[index1][index2];
            if (val == target) return true;
            if (val < target) begin = middle + 1;
            else end = middle - 1;
        }
        return false;
    }
};