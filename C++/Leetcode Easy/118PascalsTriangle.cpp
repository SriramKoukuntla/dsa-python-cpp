#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; ++i) {
            vector<int>& prevRow = res.back();
            vector<int> nextRow = {1};
            for (int i = 0; i < prevRow.size()-1; ++i) nextRow.push_back(prevRow[i] + prevRow[i+1]);
            nextRow.push_back(1);
            res.push_back(nextRow);
        }
        return res; 
    }
};