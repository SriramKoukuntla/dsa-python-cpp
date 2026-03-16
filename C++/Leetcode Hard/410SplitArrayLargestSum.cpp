#include <vector>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        //Create l, r range
        int l = 0;
        int r = 0;
        for (int num : nums) r += num;

        int res = INT_MAX;
        while (l <= r) {
            int m = l + (r-l)/2; //fancy way of doing average, so computer doesn't overflow
            int largestSubarrySum = 0;
            int currSubarraySum = 0;
            int currK = 1;
            for (int i = 0; i < nums.size(); ++i) {
                if (currSubarraySum + nums[i] > m) {
                    largestSubarrySum = max(largestSubarrySum, currSubarraySum);
                    currSubarraySum = 0;
                    ++currK;
                }
                // if (currSubarraySum == 0) ;
                currSubarraySum += nums[i];
            }
            largestSubarrySum = max(largestSubarrySum, currSubarraySum); //we need to redo the calculation here becuase we need to factor in the last subarray


            if (currK > k) l = m+1;
            else {
                res = min(res, largestSubarrySum);
                r = m-1;
            }
        }
        return res; 
    }
};
//z = largest sum we want in each subarray. if we get bigger, we just make a new sub array
//[1, sum(nums)]
//if z is too small, we will have too many k's 
//if z is too big, we will not be utilizing every k
//[7,2,5,10,8]
//