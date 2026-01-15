#include <vector> 
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Brute force double for loop iteration O(n^2)
        //[73,74,75,71,69,72,76,73]
        //[<76, 6>, <72, 5>, <71, 3> ]
        //Create a stack going backwards strictly decreasing also keep track 
        //of idx
        //[73,74,75,71,69,72,76,73]

        vector<int> res(temperatures.size());
        vector<pair<int, int>> stack;
        for (int i = temperatures.size()-1; i >= 0; --i){
            int curr = temperatures[i];
            while (!stack.empty() && stack.back().first <= curr) {
                stack.pop_back();
            }
            if (stack.empty()) res[i] = 0;
            else res[i] = stack.back().second - i;
            stack.push_back({curr, i});
        }
        return res; 
    }
};