#include <vector>
using namespace std;
int UnionFindAlgorithm(vector<vector<int>> edges, int n) {
    vector<int> parents;
    for (int i = 0; i < n; ++i) parents.push_back(i);
    vector<int> size(n, 1);

    int res = n;
    for (vector<int> edge : edges) {
        int p1 = find(parents, edge[0]);
        int p2 = find(parents, edge[1]);
        if (p1 == p2) continue;
        if (size[p2] > size[p1]) swap(p1, p2);
        parents[p2] = p1;
        size[p1] += size[p2];
        --res;
    }
    return res;
}

int find(vector<int>& parent, int node) {
    while (node != parent[node]) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}