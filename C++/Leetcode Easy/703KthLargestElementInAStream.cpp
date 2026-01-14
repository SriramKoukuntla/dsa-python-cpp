#include <queue>
#include <vector>
#include <functional>
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i = 0; i < nums.size(); ++i) pq.push(nums[i]);
        while (pq.size() > K) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#include <queue>

class KthLargest {
public:
    int capacity;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for (int num : nums){
            minHeap.push(num);
            if (minHeap.size() > capacity) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > capacity) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */