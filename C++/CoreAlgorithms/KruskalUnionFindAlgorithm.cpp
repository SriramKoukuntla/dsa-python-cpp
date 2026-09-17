//Same use case as PRIMS. Find min cost to connect all vertecies with edges.

#include <vector>
#include <queue>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > minHeap;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                vector<int> point1 = points[i];
                vector<int> point2 = points[j];
                int cost = abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
                minHeap.push({cost, i, j});
            }
        }

        vector<int> sizeOfCC(points.size(), 1);
        vector<int> parentsOfCC(points.size(), -1);
        for (int i = 0; i < parentsOfCC.size(); ++i) parentsOfCC[i] = i;

        int numVisited = 0;
        int res = 0;

        while (!minHeap.empty()) {
            auto [cost, p1, p2] = minHeap.top();
            minHeap.pop();
            if (find(parentsOfCC, p1) == find(parentsOfCC, p2)) continue;
            res += cost;
            unionOp(sizeOfCC, parentsOfCC, p1, p2);
            if (sizeOfCC[find(parentsOfCC, p1)] == points.size() || sizeOfCC[find(parentsOfCC, p2)] == points.size()) return res;
        }
        return res;
    }

private:
    int find(vector<int>& parentsOfCC, int p1) {
        return p1 == parentsOfCC[p1] ? p1 : parentsOfCC[p1] = find(parentsOfCC, parentsOfCC[p1]);
    }

    bool unionOp(vector<int>& sizeOfCC, vector<int>& parentsOfCC, int p1, int p2) {
        int root1 = find(parentsOfCC, p1);
        int root2 = find(parentsOfCC, p2);

        if (root1 == root2) return false;
        if (sizeOfCC[root2] > sizeOfCC[root1]) swap(root1, root2);
        sizeOfCC[root1] += sizeOfCC[root2];
        parentsOfCC[root2] = root1;
        return true;
    }
};