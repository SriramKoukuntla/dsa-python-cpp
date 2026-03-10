#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        //Process logs to more easy format
        vector<tuple<int, bool, int>> processedLogs;
        for (string& log : logs) {
            tuple<int, bool, int> processedLog = {-1, false, -1};
            int firstSectionEnd = log.find(':');
            get<0>(processedLog) = stoi(log.substr(0, firstSectionEnd));
            if (log[firstSectionEnd+1] == 's') get<1>(processedLog) = true;
            int thirdSectionStart = log.find(':', firstSectionEnd+1)+1;
            get<2>(processedLog) = stoi(log.substr(thirdSectionStart, log.size()-(thirdSectionStart)));
            processedLogs.push_back(processedLog);
        }


        //if we start a function, we are adding to the stack
        //if we end a function, we are removing from the stack
        //if we start a function, we add the difference in time to the function that was previously on the stack
        //if we end a function we, we add the difference in time of the current function and the previous log time stamp to the current function

        vector<int> res(n, 0);
        vector<tuple<int, bool, int>> stack;

        for (int i = 0; i < processedLogs.size(); ++i) {
            if (stack.empty()) {stack.push_back(processedLogs[i]); continue;}

            tuple<int, bool, int> currLog = processedLogs[i];
            tuple<int, bool, int> prevLog = processedLogs[i-1];
            tuple<int, bool, int> currFunc = stack.back();
            
            if (!get<1>(currLog)) {
                if (get<0>(currLog) == get<0>(prevLog) && get<1>(prevLog)) res[get<0>(currLog)] += (get<2>(currLog)-get<2>(prevLog)+1);
                else res[get<0>(currFunc)] += (get<2>(currLog)-get<2>(prevLog));
                stack.pop_back();
            }
            else {
                if (get<1>(prevLog)) res[get<0>(currFunc)] += (get<2>(currLog)-get<2>(prevLog));
                else res[get<0>(currFunc)] += (get<2>(currLog)-get<2>(prevLog))-1;
                stack.push_back(currLog);
            }
        }

        return res; 
    }
};