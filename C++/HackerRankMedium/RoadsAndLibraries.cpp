#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    //Check if creating a library for each city is cheaper than building roads to cities
    if (c_road >= c_lib) return 1LL * n * c_lib;
    
    //Create Adjacency List 
    unordered_map<int, vector<int>> adj; //[city (1 indexed), list of neighbhoring cities (1 indexed)]
    for (vector<int> roads : cities) {
        adj[roads[0]].push_back(roads[1]);
        adj[roads[1]].push_back(roads[0]);
    }
    
    //Figure out how many roads & libraries
    long long res = 0;
    unordered_set<int> visited; //1 indexed
    for (int i = 1; i <= n; ++i) {
        long long numRoads = 0;
        if (visited.find(i) != visited.end()) continue;
        //DFS Core Algorithm
        vector<int> stack = {i};
        while (!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();
            if (visited.find(curr) != visited.end()) continue;
            if (curr != i) ++numRoads;
            visited.insert(curr);
            for (int nei : adj[curr]) stack.push_back(nei);
        }
        res += (numRoads * c_road) + (c_lib);
    }
    return res;
}