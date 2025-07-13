#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i){
            int current = nums[i];
            int complement = target-current;
            if (map.find(complement) != map.end()) return {map[complement], i};
            map[current] = i;
        }
        return {-1, -1};
    }
};