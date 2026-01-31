#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = 0;
        //Creating adjacency map. Key = node, Value = list of pairs of neighbhor and distance
        unordered_map<int, vector<pair<int, int>>> map;
        for (vector<int> time : times) map[time[0]].push_back({time[1], time[2]});

        //Creating distances map (node, dst)
        unordered_map<int, int> dist;
        
        //Creating priority queue (dst, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        //Core Algorithm
        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            if (dist.find(currNode) != dist.end()) continue;
            dist[currNode] = currDist;

            res = max(res, currDist);
            for (auto [nei, neiDist] : map[currNode]) pq.push({currDist + neiDist, nei});
        }
        
        return res;
    }
};