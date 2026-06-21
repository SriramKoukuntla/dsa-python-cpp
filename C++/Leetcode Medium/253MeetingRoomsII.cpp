class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) {
            //Sort
            sort(intervals.begin(), intervals.end());
            //List of different conference last meeting time
            vector<int> conferences = {0};
    
            for (auto interval : intervals) {
                bool inserted = false;
                for (int& currConference : conferences) {
                    if (interval[0] >= currConference) {
                        currConference = interval[1];
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) conferences.push_back(interval[1]);
            }
            return conferences.size();
        }
    };
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
    
        priority_queue<int, vector<int>, greater<int>> days;
        
        for (int i = 0; i < intervals.size(); ++i){
            Interval interval = intervals[i];
            if (!days.empty() && days.top() <= interval.start){
                int temp = days.top();
                days.pop();
                days.push(interval.end);
            }
            else{
                days.push(interval.end);
            }
        }

        return days.size();
    }
};