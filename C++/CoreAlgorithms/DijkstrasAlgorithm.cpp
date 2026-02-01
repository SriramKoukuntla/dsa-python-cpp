#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

//Dijkstra's algorithm is for finding the length of the shortest path from one node to all other nodes assuming edge weights >= 0
//Input: Vector of edges: {node1, node2, weight}
//Output: Map of shortest path from node1 to node2 (key = node dst, val = shortest path length)
unordered_map<int, int> djkstraAlgorithm(vector<vector<int>> edges, int starting) {
    //Create Adjacency Map, res map, and priority queue
    unordered_map<int, vector<vector<int>>> map;
    for (vector<int> edge : edges) map[edge[0]].push_back({edge[1], edge[2]});
    unordered_map<int, int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, starting});

    //Core algorithm
    while (!pq.empty()) {
        //Get Current Node in pq
        int currDist = pq.top().first;  
        int currNode = pq.top().second;
        pq.pop();
        
        //Finalize Node
        if (res.find(currNode) != res.end()) continue;
        res[currNode] = currDist;
        
        //Relaxation of current node
        for (vector<int> edge : map[currNode]) {
            int n = edge[0];
            int w = edge[1];

            if (res.find(n) != res.end()) continue;
            pq.push({currDist + w, n});
        }
    }
    
    return res;
}



