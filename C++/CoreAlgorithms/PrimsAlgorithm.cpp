#include <vector>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <queue>
using namespace std;

int PrimsAlgorithm(vector<vector<int>> edges) {
    //Create Adjacency Matrix (assuming one direction)
    unordered_map<int, vector<pair<int, int>>> adj;
    for (vector<int> edge : edges) adj[edge[0]].push_back({edge[1], edge[2]});

    //Initialize priority queue and visited set
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    unordered_set<int> visited;
    int res = 0;

    //Core algorithm
    while (!pq.empty()) {
        auto [currDst, currNode] = pq.top();
        pq.pop();

        if (visited.find(currNode) != visited.end()) continue;
        visited.insert(currNode);
        res += currDst;

        for (auto [nei, neiDst] : adj[currNode]) pq.push({neiDst, nei});
    }

    return res;
}


