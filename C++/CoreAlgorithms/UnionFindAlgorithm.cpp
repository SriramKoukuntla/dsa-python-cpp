#include <vector>
using namespace std;
//For finding number of connected components
int find(vector<int>& parents, vector<int>& size, int node) {
    return (parents[node] == node) ? node : parents[node] = find(parents, size, parents[node]);
}

bool unionOp(vector<int>& parents, vector<int>& size, int node1, int node2) {
    int root1 = find(parents, size, node1);
    int root2 = find(parents, size, node2);
    if (root1 == root2) return false;
    
    if (size[root2] > size[root1]) swap(root1, root2);
    size[root1] += size[root2];
    parents[root2] = root1;

    return true;
}