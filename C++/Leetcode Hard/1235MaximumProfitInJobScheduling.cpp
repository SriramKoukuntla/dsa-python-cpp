#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int helper(unordered_map<int, vector<pair<int, int>>>& timing, int time, int lastTime, 
                unordered_map<int, int>& mem, unordered_map<int, int>& nextTime) {
        if (time == lastTime) return 0;
        if (mem.find(time) != mem.end()) return mem[time];
        int res = 0;
        for (auto [endTime, profit] : timing[time]) res = max(res, profit + helper(timing, endTime, lastTime, mem, nextTime));
        if (nextTime[time] != -1) res = max(res, helper(timing, nextTime[time], lastTime, mem, nextTime));
        mem[time] = res;
        return res;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        unordered_map<int, vector<pair<int, int>>> timings; //[key = starTime] [val = list of pairs [endTime, profit]]
        int lastTime = 0;
        unordered_set<int> validTimes;
        for (int i = 0; i < startTime.size(); ++i) {
            timings[startTime[i]-1].push_back({endTime[i]-1, profit[i]}); //0 indexed
            lastTime = max(lastTime, endTime[i]-1);
            validTimes.insert(startTime[i]-1);
            validTimes.insert(endTime[i]-1);
        }

        vector<int> sortedValidTimes(validTimes.begin(), validTimes.end());
        sort(sortedValidTimes.begin(), sortedValidTimes.end());


        unordered_map<int, int> nextTime; //validTime1 -> validTime2 (if last valid time, then -1);
        for (int i = 0; i < sortedValidTimes.size()-1; ++i) nextTime[sortedValidTimes[i]] = sortedValidTimes[i+1];
        nextTime[sortedValidTimes[sortedValidTimes.size()-1]] = -1;

        unordered_map<int, int> mem;
        return helper(timings, sortedValidTimes[0], lastTime, mem, nextTime);
    }
};


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