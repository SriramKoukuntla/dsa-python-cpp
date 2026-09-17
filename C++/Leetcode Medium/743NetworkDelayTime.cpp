#include <vector>
#include <unordered_map>
#include <queue>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<tuple<int, int>>> adjList; //Source : {destination, time}
        for (vector<int>& time : times) adjList[time[0]].push_back({time[1], time[2]});

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> minHeap; //{absTime, destination}
        minHeap.push({0, k});
        
        vector<bool> visited(n, false);
        int numVisited = 0;


        while (!minHeap.empty()) {
            auto [absTime, destination] = minHeap.top();
            minHeap.pop();

            if (!visited[destination]) {
                if (++numVisited == n) return absTime;
            }
            else continue;

            visited[destination] = true;

            for (auto [dst, time] : adjList[destination]) if (!visited[dst]) minHeap.push({absTime + time, dst});

        }

        return -1;
    }
};

