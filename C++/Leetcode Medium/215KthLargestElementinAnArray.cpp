#include <vector>
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int num : nums) {
            smallest = min(smallest, num);
            largest = max(largest, num);
        }

        vector<int> bucket(largest-smallest+1, 0);
        for (int num : nums) ++bucket[num-smallest];

        int counter = k;
        for (int i = bucket.size()-1; i >= 0; --i) {
            counter -= bucket[i];
            if (counter <= 0) return i + smallest;
        }
        return -1;
    }
};

#include <vector>
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};

#include <utility>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int smallestVal = INT_MAX;
        int biggestVal = INT_MIN;
        for (int num : nums) {
            smallestVal = min(smallestVal, num);
            biggestVal = max(biggestVal, num);
        }

        vector<int> buckets(1LL*biggestVal-smallestVal+1, 0);
        for (int num : nums) ++buckets[1LL*num-smallestVal];
        for (int i = buckets.size()-1; i >= 0; --i) {
            k -= buckets[i];
            if (k <= 0) return smallestVal + i;
        }
        return -1;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

#include <queue>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i) pq.push(nums[i]);
        while (pq.size() > k) pq.pop();
        return pq.top();
    }
};