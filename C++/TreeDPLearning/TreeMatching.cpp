#include <bits/stdc++.h>
using namespace std;
void helper (unordered_map<int, tuple<int, int>>& mem, 
unordered_map<int, vector<int>>& children, 
int currNode){
    if (children[currNode].empty()) {
        mem[currNode] = {0, 0};
        return;
    }
    vector<int> prefixSum(children[currNode].size(), 0); 
    vector<int> suffixSum(children[currNode].size(), 0);
    //Don't include is sum of max of choose and not choose on all subtrees
    //Include is 
    //1, 2, 3, 4, 5 
    //1, 3, 6, 10, 15
    //15, 14, 12, 9, 5

    int index = 0;
    for (int child : children[currNode]) {
        helper(mem, children, child);
        int best = max(get<0>(mem[child]), get<1>(mem[child]));
        prefixSum[index] = index == 0 ? best : best + prefixSum[index-1];
        suffixSum[suffixSum.size()-1-index] = index == 0 ? best : best + prefixSum[index+1];
    }
    get<0>(mem[currNode]) = 
    get<1>(mem[currNode]) = suffixSum.back();



}

int main(){
    int n; cin >> n;
    unordered_map<int, vector<int>> adjMat;
    for (int i = 0; i < n-1; ++i) {
        int N1; cin >> N1;
        int N2; cin >> N2;
        adjMat[N1].push_back(N2);
        adjMat[N2].push_back(N1);
    }

    unordered_map<int, vector<int>> children; //1 index, parent -> {children}
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int par = q.front();
        for (int child : adjMat[par]) {
            if (children.find(child) != children.end()) continue;
            children[par].push_back(child); 
            q.push(child);
        }
    }
    unordered_map<int, tuple<int, int>> mem; //node -> [pick, don't pick]
    // helper(children, mem, 1);
    int res = max(get<0>(mem[1]), get<1>(mem[1]));
    cout << res;
    return 0;
}