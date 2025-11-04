#include <queue>
#include <vector>


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), false);
        vector<int> dist(points.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int res = 0;
        
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int distance = top.first;
            int point = top.second;

            if (visited[point]) continue;
            visited[point] = true;
            res += distance;
            
            for (int i = 0; i < points.size(); ++i) {
                if (visited[i]) continue;
                int tempDist = abs(points[point][0] - points[i][0]) + 
                           abs(points[point][1] - points[i][1]);

                if (tempDist < dist[i]){
                    dist[i] = tempDist;
                    pq.push({tempDist, i});
                }
            }
        }
        return res;
    }
};