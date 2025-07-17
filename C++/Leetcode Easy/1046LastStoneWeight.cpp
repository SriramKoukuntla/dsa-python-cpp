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