#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;

        int res = 0;
        int currSum = 0;
        for (int num : nums) {
            currSum += num;
            res += prefixSumFreq[currSum-k];
            ++prefixSumFreq[currSum];
        }
        return res;
    }
};