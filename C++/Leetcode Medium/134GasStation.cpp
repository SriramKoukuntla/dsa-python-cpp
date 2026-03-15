class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //Create diff list
        int sum = 0;
        vector<int> diff;
        for (int i = 0; i < gas.size(); ++i) {diff.push_back({gas[i]-cost[i]}); sum += gas[i]-cost[i];}
        if (sum < 0) return -1;
        

        //Core algorithm
        int res = -1;
        int currGas = 0;
        for (int i = 0; i < diff.size(); ++i) {
            if (res == -1) res = i;
            currGas += diff[i];
            if (currGas < 0) {
                currGas = 0;
                res = -1;
            }
        }
        return res; 
    }
};

#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //Create diff list
        int sum = 0;
        list<tuple<int, int>> diff;
        for (int i = 0; i < gas.size(); ++i) {diff.push_back({gas[i]-cost[i], i}); sum += gas[i]-cost[i];}
        if (sum < 0) return -1;

        //Combination filter
        bool combined = true;
        while (combined) {
            combined = false;
            for (auto it = diff.begin(); it != diff.end();) {
                // for (auto [val, idx] : diff) cout << "(val: " << val << " idx: " << idx << "), ";
                // cout << endl; 

                //We only want to iterate from index [0, diff.size()-1]
                auto next = it;
                ++next;
                if (next == diff.end()) break;

                if (get<0>(*it) < 0 && get<0>(*next) > 0) it = next; //neg -> pos condition
                else {
                    combined = true;;
                    get<0>(*it) += get<0>(*next);
                    diff.erase(next);
                }
            }
        }

        //If size 1 case
        if (diff.size() == 1) return (get<0>(diff.front()) < 0) ? -1 : get<1>(diff.front());
        else return (get<0>(diff.front()) + get<0>(diff.back()) < 0) ? -1 : get<1>(diff.back());
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < gas.size(); ++i){
            diff.push_back(gas[i] - cost[i]);
            totalGas += gas[i];
            totalCost += cost[i];
        } 
        if (totalCost > totalGas) return -1;

        int gasCurr = 0;
        int idxCurr = -1;
        for (int i = 0; i < diff.size(); ++i){
            gasCurr += diff[i];
            if (gasCurr < 0) {
                idxCurr = -1;
                gasCurr = 0;
                continue;
            }
            if (idxCurr == -1) idxCurr = i;
        }
        return idxCurr;

    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++i){
            if (cost[i] > gas[i]) continue;
            int gasCurr = 0;
            for (int j = i; j < i + gas.size(); ++j){
                gasCurr += gas[j % gas.size()] - cost[j % gas.size()];
                if (gasCurr < 0){
                    i = j;
                    break;
                }
                if (j == i + gas.size()-1) return i;
            }
        }
        return -1;
    }
};