#include <unordered_set>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set; //can be sized k + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.size() == k+1) set.erase(nums[i-k-1]);
            if (set.find(nums[i]) != set.end()) return true;
            set.insert(nums[i]);
        }

        return false;

    }
};

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