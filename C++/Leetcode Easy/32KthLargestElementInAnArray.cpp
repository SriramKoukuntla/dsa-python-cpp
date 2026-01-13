//Two ways, Do both


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int largest = nums[0];
        int smallest = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            largest = max(largest, nums[i]);
            smallest = min(smallest, nums[i]);
        }
        vector<int> bucket(largest-smallest+1);
        for (int i = 0; i < nums.size(); ++i){
            ++bucket[nums[i]-smallest];
        }
        for (int i = bucket.size()-1; i >= 0; --i){
            k -= bucket[i];
            if (k <= 0) return smallest + i;
        }
        return -1;
    }
};

#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        auto end = nums.end();
        for (int i = 0; i < k-1; ++i){
            pop_heap(nums.begin(), end);
            --end;
        }
        return nums.front();
    }
};