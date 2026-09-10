#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mem;
    int rob(vector<int>& nums) {
        mem = vector<int>(nums.size(), -1);
        return helper(nums, nums.size()-1);
    }

    int helper(vector<int>& nums, int i) {
        if (i == 0) return nums[0];
        if (i == 1) return max(nums[0], nums[1]);
        if (mem[i] != -1) return mem[i];
        int res = max(helper(nums, i-2) + nums[i], helper(nums, i-1));
        mem[i] = res;
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> tab(nums.size(), 0);
        tab[0] = nums[0];
        tab[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) tab[i] = max(tab[i-1], nums[i] + tab[i-2]);
        return tab.back();
    }
};