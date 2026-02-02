#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<long long>> cache;
    long long maxAlternatingSum(vector<int>& nums) {
        cache = vector<vector<long long>>(2, vector<long long>(nums.size(), -1));
        cache[1][nums.size()-1] = nums[nums.size()-1]; //odd base case
        cache[0][nums.size()-1] = 0; //even base case

        for (int i = nums.size()-2; i >= 0; --i) {
            cache[1][i] = max(cache[0][i+1] + nums[i], cache[1][i+1]);
            cache[0][i] = max(cache[1][i+1] - nums[i], cache[0][i+1]);
        }
        return cache[1][0];
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        return helper(0, true, nums);
        int res = helper(0, true, nums);
    }
    //[True, False] = [Odd, Even]
    long long helper (int i, bool state, vector<int>& nums) {
        //Base Cases
        if (i == nums.size()-1 && state) return nums[i];
        else if (i == nums.size()-1 && !state) return 0;
        //Odd State
        if (state) {
            long long even = helper(i+1, false, nums) + nums[i];
            long long skip = helper(i+1, true, nums);            
            return max(even, skip);
        }
        //Even State
        else {
            long long odd = helper(i+1, true, nums) - nums[i];
            long long skip = helper(i+1, false, nums);
            return max(odd, skip);
        }
    }
};

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