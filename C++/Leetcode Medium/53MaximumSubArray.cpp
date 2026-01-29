class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = 0;
        int l = 0; 
        for (int r = 0; r < nums.size(); ++r) {
            while (curr < 0 && l < r) curr -= nums[l++];
            curr += nums[r];
            res = max(res, curr);
        }
        return res;
    }
};