#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<pair<int, int>> stack; //idx, val;
        for (int i = 0; i < heights.size(); ++i) {
            int start = i;
            while (!stack.empty() && stack.back().second > heights[i]) {
                auto [stackBackIdx, stackBackVal] = stack.back();
                stack.pop_back();
                res = max(res, (i-stackBackIdx)*stackBackVal);
                start = stackBackIdx;
            }
            stack.push_back({start, heights[i]});
        }
        while (!stack.empty()) {
            auto [stackBackIdx, stackBackVal] = stack.back();
            stack.pop_back();
            res = max(res, (int)((heights.size() - stackBackIdx) * stackBackVal));
        }
        return res;
    }
};