#include <vector>
#include <queue>

using namespace std;
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (vector<Interval> intervals : schedule) for (Interval interval : intervals) pq.push({interval.start, interval.end});

        vector<pair<int, int>> intervals;
        int bigStart = pq.top().first;
        int bigEnd = pq.top().second;
        pq.pop();

        while (!pq.empty()) {
            auto [currStart, currEnd] = pq.top();
            pq.pop();
            if (currStart <= bigEnd) bigEnd = max(bigEnd, currEnd);
            else {
                intervals.push_back({bigStart, bigEnd});
                bigStart = currStart;
                bigEnd = currEnd;
            }
        }
        intervals.push_back({bigStart, bigEnd});

        vector<Interval> res;
        for (int i = 0; i < intervals.size()-1; ++i) {
            res.push_back(Interval(intervals[i].second, intervals[i+1].first));
        }
        return res;
    }
};