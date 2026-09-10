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