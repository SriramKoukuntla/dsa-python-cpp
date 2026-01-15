#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) ++map[num];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //first int is for frequency, second is for number itself
        for (auto [num, freq] : map) pq.push({freq, num});
        //nums1 is number itself, num2 is frequency
        while (pq.size() > k) pq.pop();
        vector<int> res;
        while (pq.size() > 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};