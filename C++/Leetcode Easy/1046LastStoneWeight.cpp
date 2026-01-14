#include <queue> 
#include <vector>
#include <cstdlib> 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); ++i) pq.push(stones[i]);
        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if (stone1 == stone2) continue;
            pq.push(abs(stone1-stone2));
        }
        if (pq.size() == 0) return 0;
        else return pq.top();
    }
};

#include <queue>
class Solution {
public:
    priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for (int stone : stones){
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(stone1-stone2);
        }
        return maxHeap.top();
    }
};