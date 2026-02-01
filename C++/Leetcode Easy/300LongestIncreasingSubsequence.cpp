#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> tab(nums.size());
        for (int i = nums.size()-1; i >= 0; --i) {
            int maxVal = 0;
            for (int j = i+1; j < nums.size(); ++j) if (nums[j] > nums[i]) maxVal = max(maxVal, tab[j]);
            tab[i] = 1 + maxVal;
            res = max(res, tab[i]);
        }
        return res;
    }
};
