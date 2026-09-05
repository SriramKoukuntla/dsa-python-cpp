#include <vector>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        for (int num : nums) {
            int n = subsets.size();
            for (int i = 0; i < n; ++i) {
                vector<int> subset = subsets[i];
                subset.push_back(num);
                subsets.push_back(subset);
            }
        }
        int res = 0;
        for (vector<int>& subset : subsets) {
            int temp = 0;
            for (int item : subset) temp ^= item;
            res += temp;
        }
        return res; 
    }
};

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