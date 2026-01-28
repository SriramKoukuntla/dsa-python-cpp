#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }
                else if (sum < 0) ++l;
                else if (sum > 0) --r;
            }
        }
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) continue;
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l-1] == nums[l]) ++l;
                    while (l < r && nums[r+1] == nums[r]) --r;
                }
                else if (sum > 0) --r;
                else ++l;
            }
        }
        return res;
    }
};
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
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