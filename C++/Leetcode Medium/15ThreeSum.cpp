#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // skip duplicate i
            if (nums[i] > 0) break; 
            int curr = nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while (l < r){
                if (curr + nums[l] + nums[r] > 0) --r;
                else if (curr + nums[l] + nums[r] < 0) ++l;
                else {
                    res.push_back({curr, nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }
            }
        }
        return res;
    }
};