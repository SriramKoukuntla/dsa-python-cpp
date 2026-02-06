#include <vector>
#include <queue>
using namespace std;
int luckBalance(int k, vector<vector<int>> contests) {
    //if unimportant just add that to luck balance. if important add to max heap
    //after removing k entries we add those k entries to luck balance, and then subtract the rest
    int res = 0;
    priority_queue<int> pq;
    for (vector<int> contest : contests) {
        if (contest[1] == 0) res += contest[0];
        else pq.push(contest[0]);
    }

    int n = min((int)pq.size(), k);
    for (int i = 0; i < n; ++i) {
        res += pq.top();
        pq.pop();
    }
    
    n = pq.size();
    for (int i = 0; i < n; ++i) {
        res -= pq.top();
        pq.pop();
    }
    return res;
}