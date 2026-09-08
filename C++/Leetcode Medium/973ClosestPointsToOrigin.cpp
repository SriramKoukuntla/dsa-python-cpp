#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<double>> p;
        for (vector<int> point : points) {
            double distance = sqrt(point[0] * point[0] + point[1] * point[1]); 
            p.push_back({distance, (double)point[0], (double)point[1]});
        }
        sort(p.begin(), p.end());
        while (p.size() > k) p.pop_back();

        vector<vector<int>> res;
        for (vector<double> temp : p) res.push_back({(int)temp[1], (int)temp[2]});

        return res;
    }
};

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>> pq;
        for (vector<int> point : points) {
            double distance = sqrt(point[0] * point[0] + point[1] * point[1]); 
            vector<double> temp = {distance, (double)point[0], (double)point[1]};
            pq.push(temp);
            if (pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> res;
        while (!pq.empty()) {
            vector<double> curr = pq.top();
            res.push_back({(int)curr[1], (int)curr[2]});
            pq.pop();
        }

        return res;
    }
};

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