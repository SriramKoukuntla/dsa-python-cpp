#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target-nums[i]) != map.end()) return {i, map[target-nums[i]]};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target-nums[i]) != map.end()) {
                int j = map[target-nums[i]];
                return {i, j};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            int compliment = target-num;
            if (map.find(compliment) != map.end()) return {i, map[compliment]};
            map[num] = i;
        }
        return {0, 0};
    }
};

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