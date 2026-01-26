#include <vector> 
#include <algorithm> 
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp;
        for (int n : nums) temp.push_back(n);

        sort(temp.begin(), temp.end());
        unordered_map<int, int> map;
        for (int i = 0; i < temp.size(); ++i) {
            if (i != 0 && temp[i] == temp[i-1]) continue;
            map[temp[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) res.push_back(map[nums[i]]);
        return res;
    }
};