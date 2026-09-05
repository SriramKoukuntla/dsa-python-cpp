#include <vector>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subSets;
        vector<int> temp; 
        helper(nums, subSets, temp, 0);
        int res = 0;
        for (vector<int>& subSet : subSets) {
            int temp = 0;
            for (int item : subSet) temp ^= item;
            res += temp;
        }
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& subSets, vector<int>& temp, int index) {
        if (index == nums.size()) {
            subSets.push_back(temp);
            return;
        }

        //don't choose branch
        helper(nums, subSets, temp, index+1);

        //choose branch
        temp.push_back(nums[index]);
        helper(nums, subSets, temp, index+1);
        temp.pop_back();
    }
};