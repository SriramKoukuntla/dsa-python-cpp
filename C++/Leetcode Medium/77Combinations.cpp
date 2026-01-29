#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res = {};
        vector<int> temp = {};
        helper(temp, res, 1, k, n);
        return res;
    }
     
    void helper(vector<int>& temp, vector<vector<int>>& res, int curr, int k, int n) {
        if (temp.size() >= k) {
            res.push_back(temp);
            return;
        }
        for (int i = curr; i <= n; ++i) {
            temp.push_back(i);
            helper(temp, res, i+1, k, n);
            temp.pop_back();
        }
        return;
    }
};