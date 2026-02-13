#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        unordered_map<int, vector<pair<int, int>>> timings; //[start, [endTime, profit]] (zero indexed)
        for (int i = 0; i < startTime.size(); ++i) timings[startTime[i]-1].push_back({endTime[i]-1, profit[i]});

        unordered_set<int> set;
        for (int time : endTime) set.insert(time-1);
        for (int time : startTime) set.insert(time-1);
        vector<int> listOfTimes(set.begin(), set.end());
        sort(listOfTimes.begin(), listOfTimes.end(), greater<int>());

        unordered_map<int, int> tab;
        for (int i = 0; i < listOfTimes.size(); ++i) {
            int currTime = listOfTimes[i];
            int maxVal = (i != 0) ? tab[listOfTimes[i-1]] : 0;
            for (auto [endTime, money] : timings[currTime]) {
                maxVal = max(maxVal, money + tab[endTime]);
            }
            tab[currTime] = maxVal;
        }
        
        return tab[listOfTimes[listOfTimes.size()-1]];
    }
};