class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Count number of elements
        unordered_map<int, int> freq;
        for (int num : nums) ++freq[num];

        //Create min heap (pair<int, int> [freq, num]), and only keep the top K Frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [number, frequency] : freq) {
            pq.push({frequency, number});
            if (pq.size() > k) pq.pop();
        }

        //Push remaining elements in min heap to res vector to return top K frequent elements 
        vector<int> res;
        while (pq.size() > 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num : nums) ++count[num];

        vector<vector<int>> temp(nums.size());
        for (pair<int, int> p : count) temp[p.second-1].push_back(p.first);

        vector<int> res;
        for (int i = temp.size()-1; i >= 0; --i) {
            vector<int> curr = temp[i];
            for (int num : curr) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return {};
    }
};

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