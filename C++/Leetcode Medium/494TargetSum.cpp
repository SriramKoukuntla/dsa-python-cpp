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