#include <vector>
#include <list>
using namespace std;
void inOrderTraversal(vector<vector<int>>& indexes, int curr, vector<int>& res) {    
    if (indexes[curr-1][0] != -1) inOrderTraversal(indexes, indexes[curr-1][0], res);
    res.push_back(curr);
    if (indexes[curr-1][1] != -1) inOrderTraversal(indexes, indexes[curr-1][1], res);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> res;
    for (int query : queries) {
        list<pair<int, int>> queue = {{1, 1}};
        while (!queue.empty()) {
            auto [index, depth] = queue.front();
            queue.pop_front();
            if (depth % query == 0) swap(indexes[index-1][0], indexes[index-1][1]);
            int L = indexes[index-1][0];
            int R = indexes[index-1][1];
            if (L != -1) queue.push_back({L, depth + 1});
            if (R != -1) queue.push_back({R, depth + 1});
        }
        vector<int> tempRes;
        inOrderTraversal(indexes, 1, tempRes);
        res.push_back(tempRes);
                
    }
    return res;    
}