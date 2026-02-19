#include <unordered_map>
using namespace std;

class Solution {
public:
    long long getBucketId(int element, int valueDiff) {
        if (element >= 0) return element / (valueDiff+1);
        else return ((element+1) / (valueDiff+1))-1;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long long, int> buckets; //bucketId, val aka nums[i]
        
        for (int i = 0; i < nums.size(); ++i) {
            if (buckets.size() == indexDiff+1) {
                //kick out nums[i-indexDiff-1]
                long long bucketId = getBucketId(nums[i-indexDiff-1], valueDiff);
                buckets.erase(bucketId);
            }

            long long currElementBucketId = getBucketId(nums[i], valueDiff);
            if (buckets.find(currElementBucketId) != buckets.end()) return true;
            if (buckets.find(currElementBucketId-1) != buckets.end() && abs(buckets[currElementBucketId-1]-nums[i]) <= valueDiff) return true;
            if (buckets.find(currElementBucketId+1) != buckets.end() && abs(buckets[currElementBucketId+1]-nums[i]) <= valueDiff) return true;

            buckets[currElementBucketId] = nums[i];
        }
        return false;
    }
};


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
