#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //Create adjacency matrix key = node, value = vector[{neighbhor, dist}]
        unordered_map<int, vector<pair<int, int>>> edges;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                edges[i].push_back({j, abs(x1-x2) + abs(y1-y2)});
            }
        }

        int res = 0;
        unordered_map<int, int> dst;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        //Core algorithm; 
        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            if (dst.find(currNode) != dst.end()) continue;
            dst[currNode] = currDist;
            res += currDist;

            for (auto [nei, neiDst] : edges[currNode]) pq.push({neiDst, nei});
        }

        return res;
    }
};