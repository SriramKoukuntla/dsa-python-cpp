#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
            else if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); ++j) res.push_back(intervals[j]);
                return res;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        vector<vector<int>> res;
        auto it = intervals.begin();
        while (it != intervals.end()){
            vector<int> curr = *it;
            //Curr before
            if (curr[0] < newInterval[0] && curr[1] < newInterval[0]) res.push_back(curr);
            //newInterval before
            else if (newInterval[0] < curr[0] && newInterval[1] < curr[0]){
                res.push_back(newInterval);
                inserted = true;
                break;
            }
            else {
                newInterval[0] = min(curr[0], newInterval[0]);
                newInterval[1] = max(curr[1], newInterval[1]);
            } 
            ++it;
        }

        while (it != intervals.end()){
            res.push_back(*it);
            ++it;
        }
        if (!inserted) res.push_back(newInterval);

        return res;
    }
};