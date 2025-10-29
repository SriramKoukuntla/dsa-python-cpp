#include <deque>
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i){
            if (res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};


#include <vector>
#include <deque>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](vector<int> v1, vector<int> v2){return v1[0] < v2[0];});

        deque<vector<int>> temp(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(*temp.begin());
        temp.pop_front();
        for (auto i = temp.begin(); i != temp.end(); ++i){
            if (res[res.size()-1][1] < (*i)[0]){
                res.push_back(*i);
            }
            else{
                res[res.size()-1][1] = max(res[res.size()-1][1], (*i)[1]);
            }
        }

        return res;
    }
};