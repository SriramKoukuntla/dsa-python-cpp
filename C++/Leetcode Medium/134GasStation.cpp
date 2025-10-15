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