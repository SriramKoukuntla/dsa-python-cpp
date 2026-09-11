#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    int helper(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = (l + r)/2;
        int leftMax = helper(nums, l, m);
        int rightMax = helper(nums, m+1, r);

        int sum = 0;
        int bestSuffix = INT_MIN;
        for (int i = m; i >= l; --i) {
            sum += nums[i];
            bestSuffix = max(bestSuffix, sum);
        }

        sum = 0;
        int bestPrefix = INT_MIN;
        for (int i = m+1; i <= r; ++i) {
            sum += nums[i];
            bestPrefix = max(bestPrefix, sum);
        }

        return max({leftMax, rightMax, bestPrefix+bestSuffix});
    }
};

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