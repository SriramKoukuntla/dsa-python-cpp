#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int currNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                currNum = nums[i];
                count = 1;
            }
            else if (nums[i] == currNum) {
                ++count;
            }
            else {
                --count;
            }
        }
        return currNum;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<pair<int, int>> bitCounting(32, {0, 0}); //key = what bit, value freq of 0 & 1
        for (int i = 0; i < nums.size(); ++i) {
            int currNum = nums[i];
            long mask = 1;
            for (int j = 0; j < 32; ++j) {
                if (currNum & mask) ++ bitCounting[j].second;
                else ++bitCounting[j].first;
                mask <<= 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (bitCounting[i].first > bitCounting[i].second) continue;
            int insertBit = 1 << i;
            res = res | insertBit;
        }

        return res;
    }
};