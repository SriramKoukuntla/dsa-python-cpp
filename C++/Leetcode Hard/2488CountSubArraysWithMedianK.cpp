#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for (int& num : nums) {
            if (num < k) num = -1;
            else if (num > k) num = 1;
            else num = 0;
        }

        unordered_map<int, int> map;
        ++map[0];
        vector<int> prefixSum(nums.size(), 0);
        bool kSeen = false;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i] = (i == 0) ? nums[i] : prefixSum[i-1] + nums[i];
            if (nums[i] == 0) kSeen = true;
            if (!kSeen) ++map[prefixSum[i]];
            else {
                int target1 = prefixSum[i];
                int target2 = prefixSum[i]-1;
                res += (map[target1] + map[target2]);
            }
        }
        return res; 
    }
};