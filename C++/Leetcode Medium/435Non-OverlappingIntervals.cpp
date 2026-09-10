class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int res = 0;
        long validStartTime = LONG_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] >= validStartTime) validStartTime = intervals[i][1];
            else ++res; 
        }
        return res;
    }
};