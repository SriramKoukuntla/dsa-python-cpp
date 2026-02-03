//Tabulation?
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        int half = sum /2;

        unordered_set<int> set;
        set.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int> tempSet;
            for (int num : set) {
                int toBeInserted = num + nums[i];
                if (toBeInserted == half) return true;
                if (toBeInserted > half) continue;
                if (set.find(toBeInserted) == set.end() && tempSet.find(toBeInserted) == tempSet.end()) tempSet.insert(toBeInserted);
            }
            set.insert(tempSet.begin(), tempSet.end());
        }
        return false;
    }
};

//Recursion + Memoization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        //[0, 1, 2] = [not visited, failure, pass]
        vector<vector<char>> mem(nums.size(), vector<char>(sum/2+1, 0));
        return helper(nums, 0, 0, sum/2, mem);
    }

    bool helper(vector<int>& nums, int i, int currSum, int half, vector<vector<char>>& mem) {
        if (currSum == half) return true;
        if (i >= nums.size() || currSum > half) return false;
        if (mem[i][currSum] != 0) return mem[i][currSum] == 2;

        bool add = helper(nums, i+1, currSum+nums[i], half, mem);
        bool skip = helper(nums, i+1, currSum, half, mem);
        if (add || skip) mem[i][currSum] = 2;
        else mem[i][currSum] = 1;
        return mem[i][currSum] == 2;
    }
};

//Recursion
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        return helper(nums, 0, 0, sum/2);
    }

    bool helper(vector<int>& nums, int i, int currSum, int half) {
        if (currSum == half) return true;
        if (i >= nums.size() || currSum > half) return false;

        bool add = helper(nums, i+1, currSum+nums[i], half);
        bool skip = helper(nums, i+1, currSum, half);
        if (add || skip) return true;
        return false;
    }
};