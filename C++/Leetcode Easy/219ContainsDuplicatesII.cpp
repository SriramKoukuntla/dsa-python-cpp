#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (r-l > k) set.erase(nums[l++]);
            if (set.find(nums[r]) != set.end()) return true;
            set.insert(nums[r]);
        }
        return false;
    }
};