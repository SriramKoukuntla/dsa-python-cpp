#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //[4,2,1,3]
        //1, 2, 3, 4
        vector<vector<int>> res;
        int minDiff = 100000000;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i]-arr[i-1] < minDiff) {
                minDiff = arr[i]-arr[i-1];
                res = {};
                res.push_back({arr[i-1], arr[i]});
            }
            else if (arr[i]-arr[i-1] == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};