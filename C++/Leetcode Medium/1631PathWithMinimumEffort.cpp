#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> knownEffort(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; //{effort, i, j}
        minHeap.push({0, 0, 0});
        while (!minHeap.empty()) {
            vector<int> curr = minHeap.top();
            int currEffort = curr[0];
            int currI = curr[1];
            int currJ = curr[2];
            minHeap.pop();
            if (currEffort >= knownEffort[currI][currJ]) continue;
            knownEffort[currI][currJ] = currEffort;
            if (currI == heights.size()-1 && currJ == heights[0].size()-1) return currEffort;
            if (currI != heights.size()-1) minHeap.push({max(currEffort, abs(heights[currI+1][currJ]-heights[currI][currJ])), currI+1, currJ});
            if (currI != 0) minHeap.push({max(currEffort, abs(heights[currI-1][currJ]-heights[currI][currJ])), currI-1, currJ});
            if (currJ != heights[0].size()-1) minHeap.push({max(currEffort, abs(heights[currI][currJ+1]-heights[currI][currJ])), currI, currJ+1});
            if (currJ != 0) minHeap.push({max(currEffort, abs(heights[currI][currJ-1]-heights[currI][currJ])), currI, currJ-1});
        }
        return -1;
    }
};