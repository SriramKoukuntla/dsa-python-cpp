#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> ms;
        for (int i = 0; i < nums.size(); ++i) {

            if (ms.size() == indexDiff+1) ms.erase(ms.find(nums[i-indexDiff-1]));

            auto start = ms.lower_bound(nums[i]-valueDiff);
            auto end = ms.upper_bound(nums[i]+valueDiff);
            for (; start != end; ++start) return true;

            ms.insert(nums[i]);
        }
        return false;
    }
};
