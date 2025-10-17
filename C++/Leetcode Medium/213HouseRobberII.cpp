class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int res1 = helper(nums, 0, nums.size()-2);
        int res2 = helper(nums, 1, nums.size()-1);

        return max(res1, res2);
    }
private:
    int helper(vector<int>& nums, int start, int finish){
        vector<int> mem(finish-start+1, 0);
        mem[0] = nums[start];
        mem[1] = max(nums[start], nums[start+1]);
        for (int i = start+2; i < finish+1; ++i){
            int j = i - start;
            mem[j] = max(mem[j-2]+nums[i], mem[j-1]);
        }
        return mem[mem.size()-1];
    }
};