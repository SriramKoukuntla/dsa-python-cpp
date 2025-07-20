#include <queue>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, vector<int>>> maxHeap;
        for (int i = 0; i < points.size(); ++i){
            int distance = pow(points[i][0], 2) +  pow(points[i][1], 2);
            maxHeap.emplace(distance * -1, points[i]);
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i){
            res.push_back(get<1>(maxHeap.top()));
            maxHeap.pop();
        }
        return res;
    }
};