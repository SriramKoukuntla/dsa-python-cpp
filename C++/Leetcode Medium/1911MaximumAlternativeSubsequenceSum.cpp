#include <vector>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> odds(nums.size());
        odds[0] = nums[0];
        vector<long long> evens(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            odds[i] = max(odds[i-1], evens[i-1]+nums[i]);
            evens[i] = max(evens[i-1], odds[i-1]-nums[i]);
        }
        return max(odds[nums.size()-1], evens[nums.size()-1]);
    }
};