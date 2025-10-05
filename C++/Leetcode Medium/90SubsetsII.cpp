#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(res, temp, nums);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void helper(set<vector<int>>& res, vector<int>& perm, vector<int>& nums){
        res.insert(perm);
        while (nums.size() > 0){
            perm.push_back(nums[0]);
            vector<int> tempNums;
            tempNums.insert(tempNums.end(), nums.begin() + 1, nums.end());
            nums = tempNums;
            helper(res, perm, tempNums);
            perm.pop_back();
        }
    }
};