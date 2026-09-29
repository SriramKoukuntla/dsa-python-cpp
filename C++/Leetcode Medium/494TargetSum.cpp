#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = 0;
        for (int num : nums) n += num;
        if (abs(target) > n) return 0;
        vector<vector<int>> tab(nums.size()+1, vector<int>((2*n)+1, 0));
        target += n;
        tab.back()[target] = 1;

        for (int i = nums.size()-1; i >= 0; --i) {
            int currNum = nums[i];
            for (int j = 0; j < tab[0].size(); ++j) {
                tab[i][j] = 0;
                if (j + currNum < tab[0].size()) tab[i][j] += tab[i+1][j+currNum];
                if (j-currNum >= 0) tab[i][j] += tab[i+1][j-currNum];
            }
        }
        return tab[0][n];
    }
};
//state: index, sum
//tab[i][sum] = using the number from i onwards given sum, how many ways to reach target;

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> cache;
        return dfs(cache, nums, target, 0);
    }
    int dfs (unordered_map<int, unordered_map<int, int>>& cache, vector<int>& nums, int target, int index) {
        if (index == nums.size() && target == 0) return 1;
        if (index == nums.size() && target != 0) return 0;
        if (cache[target].find(index) != cache[target].end()) return cache[target][index];
        int add = dfs(cache, nums, target+nums[index], index+1);
        int subtract = dfs(cache, nums, target-nums[index], index+1);
        int res = add + subtract;
        cache[target][index] = res;
        return res;
    }
};

//DFS + DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        vector<vector<int>> mem(nums.size(), vector<int>(sum+sum+1, -1));
        return helper(nums, target, 0, 0, mem, sum);   
    }

    int helper(vector<int>& nums, int target, int i, int currSum, vector<vector<int>>& mem, int sum) {
        if (i >= nums.size()) return (currSum == target) ? 1 : 0;
        if (mem[i][currSum + sum] != -1) return mem[i][currSum + sum];
        int add = helper(nums, target, i+1, currSum + nums[i], mem, sum);
        int subtract = helper(nums, target, i+1, currSum - nums[i], mem, sum);
        mem[i][currSum + sum] = add+subtract;
        return add+subtract;
    }
};

//Normal Dfs
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);   
    }

    int helper(vector<int>& nums, int target, int i, int currSum) {
        if (i >= nums.size()) return (currSum == target) ? 1 : 0;
        int add = helper(nums, target, i+1, currSum + nums[i]);
        int subtract = helper(nums, target, i+1, currSum - nums[i]);
        return add+subtract;
    }
};

//Caching DFS
#include <unordered_map>
#include <vector>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) total += nums[i];
        
        unordered_map<long long, int> mem;
        return dfs(nums, target, 0, 0, mem, total);
    }
private:
    int dfs(vector<int>& nums, int target, int curr, int index, unordered_map<long long, int>& mem, int shift){
        
        uint64_t key = ((uint64_t)index << 32 ) ^ (uint32_t)(curr + shift);

        if (mem.find(key) != mem.end()) return mem[key];

        if (index == nums.size()) return (curr == target) ? 1 : 0;
    
        int add = dfs(nums, target, curr + nums[index], index+1, mem, shift);
        int sub = dfs(nums, target, curr - nums[index], index+1, mem, shift);
        int res = add + sub;
        mem[key] = res;
        return res;
    }
};

//Backtracing DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        dfs(res, 0, 0, nums, target);   
        return res;
    }
private:
    void dfs(int& res, int sum, int index, vector<int>& nums, int target){
        if (index == nums.size()){
            if (sum == target) res += 1;
            return;
        }
        dfs(res, sum+nums[index], index+1, nums, target);
        dfs(res, sum-nums[index], index+1, nums, target);
    }
};