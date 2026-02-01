//Kahn's algorithm is used mainly for topologically sorting a directed graph + detecting for cycles

#include <vector>
#include <list>
#include <unordered_set>
using namespace std;
vector<int> KahnsAlgorithm (vector<vector<int>> directedEdges, int n) {
    //directedEdges [[0, 1], [2, 0], [1, 2]] means 0 points to 1. 2 points to 0. 1 points to 2.
    //outGoingEdges and indegree initialization
    vector<vector<int>> outgoingEdges(n, vector<int>(0));
    vector<int> indegree(n, 0);
    for (vector<int> directedEdge : directedEdges) {
        outgoingEdges[directedEdge[0]].push_back(directedEdge[1]);
        ++indegree[directedEdge[1]];
    }

    //Adding out starting nodes to queue
    list<int> queue;
    unordered_set<int> visited;
    for (int i = 0; i < indegree.size(); ++i) if (indegree[i] == 0) queue.push_back(i);
    vector<int> res;

    //Core algorithm
    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop_front();
        if (visited.find(curr) != visited.end()) return {}; //Checking for cycle
        visited.insert(curr);
        res.push_back(curr);
        for (int outgoingNode : outgoingEdges[curr]) if (--indegree[outgoingNode] == 0) queue.push_back(outgoingNode);
    }
    return (res.size() == n) ? res : vector<int>();
}