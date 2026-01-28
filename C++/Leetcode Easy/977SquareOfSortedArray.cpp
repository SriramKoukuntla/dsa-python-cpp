class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) nums[i] = nums[i] * nums[i];
        vector<int> temp;
        int l = 0; 
        int r = nums.size()-1;
        while (l <= r) {
            if (nums[l] > nums[r]) {
                temp.push_back(nums[l]);
                ++l;
            }
            else {
                temp.push_back(nums[r]);
                --r;
            }
        }
        vector<int> res;
        for (int i = temp.size()-1; i >= 0; --i) res.push_back(temp[i]);
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        return nums;
    }
};