#include <algorithm>
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(0, candidates, {}, 0, target);
        return res;
    }

    void helper(int index, vector<int>& candidates, vector<int> curr, int sum, int target){
        if (sum == target) res.push_back(curr);
        if (sum >= target) return;
        for (int i = index; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            helper(i, candidates, curr, sum + candidates[i], target);
            curr.pop_back();
        }
    }
};
