#include <bits/stdc++.h>
using namespace std;
int dfs(int node, unordered_map<int, int>& subtreeSize, 
    unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& adjMat) {
    
    if (visited.find(node) != visited.end()) return 0;
    visited.insert(node);
    int ans = 1 ;
    for (int child : adjMat[node]) ans += dfs(child, subtreeSize, visited, adjMat);    
    subtreeSize[node] = ans;
    return ans;
}

long long helper(vector<int>& sizeOfComponents) {
    long long sum = 0;
    long long sumSq = 0;

    for (int component : sizeOfComponents) {
        sum += component;
        sumSq += 1LL * component * component;
    }

    return (sum * sum - sumSq) / 2;
}



int main() {
    int n; cin >> n; 
    unordered_map<int, unordered_set<int>> adjMat;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        adjMat[a].insert(b);
        adjMat[b].insert(a);
    }

    unordered_map<int, int> subtreeSize;
    unordered_set<int> visited; 
    dfs(0, subtreeSize, visited, adjMat);

    long long mostMissedConnections = -1;
    long long temp = 0;
    int junctionToRemove = -1;
    for (int i = 0; i <= n; ++i) {
        vector<int> sizeOfComponents;
        int sizeOfCurrentSubTree = subtreeSize[i];
        int N = n + 1;
        for (int neigh : adjMat[i]) {
            if (subtreeSize[neigh] < sizeOfCurrentSubTree) sizeOfComponents.push_back(subtreeSize[neigh]);
            else sizeOfComponents.push_back(N - subtreeSize[i]);
        }
        sort(sizeOfComponents.begin(), sizeOfComponents.end());

        int brokenConnections = helper(sizeOfComponents);
        if (brokenConnections > mostMissedConnections) {
            mostMissedConnections = brokenConnections;
            junctionToRemove = i;

            if (sizeOfComponents.size() >= 2) {
                int big1 = sizeOfComponents[sizeOfComponents.size()-1];
                int big2 = sizeOfComponents[sizeOfComponents.size()-2];
                temp = 1LL * big1 * big2;            
            }
        }
    }
    cout << mostMissedConnections << " " << mostMissedConnections - temp;
    return 0;
}
//Find critical junction
//connect two biggest connected components
//Find  