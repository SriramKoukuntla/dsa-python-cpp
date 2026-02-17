#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (vector<int>& edge : edges) ++indeg[edge[1]];
        vector<int> res;
        for (int i = 0; i < indeg.size(); ++i) if (indeg[i] == 0) res.push_back(i);
        return res;
    }
};