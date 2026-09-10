#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int currSum = 0;
        int l = 0; 
        for (int r = 0; r < nums.size(); ++r) {
            currSum += nums[r];
            res = max(res, currSum);
            while (currSum < 0) currSum -= nums[l++];
        }
        return res; 
    }
};