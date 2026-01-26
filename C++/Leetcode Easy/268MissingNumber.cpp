#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> res(nums.size()+1, false);
        for (int n : nums) res[n] = true;
        for (int i = 0; i < res.size(); ++i) if (!res[i]) return i;
        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size()+1; ++i){
            res ^= i;
        }
        for (int i = 0; i < nums.size(); ++i){
            res ^= nums[i];
        }
        return res;
    }
};