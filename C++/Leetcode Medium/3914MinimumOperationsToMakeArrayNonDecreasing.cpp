#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        long long minOperations(vector<int>& nums) {
            long long res = 0;
            for (int i = 1; i < nums.size(); ++i) res += max(0, nums[i-1]-nums[i]);
            return res;
        }
    };