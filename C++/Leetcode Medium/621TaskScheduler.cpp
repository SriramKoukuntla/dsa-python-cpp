#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) ++freq[task];
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, greater<tuple<int, int, char>>> pq; //time, freq, task (time = when task is available)
        for (auto [currTask, currFreq] : freq) pq.push({0, -1 * currFreq, currTask});
        int res = 0;
        while (!pq.empty()) {
            auto [earliestAvailble, currFreq, currTask] = pq.top();
            pq.pop();
            if (earliestAvailble > res) res = earliestAvailble;
            if (currFreq + 1 < 0) pq.push({earliestAvailble + n+1, currFreq+1, currTask});
            ++res;
        }
        return res;
    }
};