#include <vector>
using namespace std;
int BellmanFord (vector<vector<int>> edges, int n, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < k+1; ++i) {
        vector<int> tempDist = dist;
        for (vector<int> edge : edges) {
            int fromNode = edge[0];
            if (dist[fromNode] == INT_MAX) continue;
            int toNode = edge[1];
            int weight = edge[2];
            tempDist[toNode] = min(tempDist[toNode], dist[fromNode] + weight);    
        }
        dist = tempDist;
    }
    if (dist[dst] == INT_MAX) return -1;
    return dist[dst];
}