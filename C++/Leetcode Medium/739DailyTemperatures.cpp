#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //[73,74,75,71,69,72,76,73]
        //[<76, 6>, <72, 5>, <71, 3>]
        //[...,2, 1, 1, 0, 0]
        vector<pair<int, int>> stack; //Temp, index
        vector<int> res(temperatures.size());
        for (int i = temperatures.size()-1; i >= 0; --i) {
            while (!stack.empty() && temperatures[i] >= stack.back().first) stack.pop_back();
            stack.push_back({temperatures[i], i});
            if (stack.size() == 1) res[i] = 0;
            else res[i] = stack[stack.size()-2].second-i;
        }
        return res;
    }
};

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