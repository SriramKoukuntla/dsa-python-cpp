#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        priority_queue<double> pq;
        for (string& price : prices) {
            double priceDouble = stod(price);
            target -= floor(priceDouble); 
            if (priceDouble - floor(priceDouble)) pq.push(priceDouble - floor(priceDouble));
        }
        if (target < 0) return "-1";
        
        double res = 0;
        while (!pq.empty()) {
            double currVal = pq.top();
            pq.pop();
            if (target > 0) {
                double temp = 1-currVal;
                --target;
                res += (1-currVal);
            }
            else {
                res += currVal;
            }


        }
        if (target != 0) return "-1";

        string resStr = to_string(res);
        int dotIdx = 0;
        while (resStr[dotIdx] != '.') ++dotIdx;
        return resStr.substr(0, dotIdx + 3 + 1);
    }
};