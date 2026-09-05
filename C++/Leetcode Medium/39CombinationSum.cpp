class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> subSets;
        vector<int> temp;
        helper(subSets, temp, 0, candidates, target, 0);
        return subSets;
    }
    void helper(vector<vector<int>>& subSets, vector<int>& temp, int sum, vector<int>& candidates, int target, int index) {
        if (sum > target) return;
        if (index == candidates.size()) return;
        if (sum == target) {
            subSets.push_back(temp);
            return;
        }

        //don't choose branch
        helper(subSets, temp, sum, candidates, target, index+1);

        //choose branch
        temp.push_back(candidates[index]);
        sum += candidates[index];
        helper(subSets, temp, sum, candidates, target, index);
        temp.pop_back();
        sum -= candidates[index];
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, int currSum, vector<int>& combination,
                vector<vector<int>>& res) {
        if (currSum == target) {res.push_back(combination); return;}
        else if (currSum > target || index >= candidates.size()) return;
        combination.push_back(candidates[index]);
        helper(candidates, target, index, currSum + candidates[index], combination, res); //Taking repicking same element
        combination.pop_back();
        helper(candidates, target, index+1, currSum, combination, res); //Skipping current element taking next element
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        helper(candidates, target, 0, 0, combination, res);
        return res;
    }
};


#include <algorithm>
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(0, candidates, {}, 0, target);
        return res;
    }

    void helper(int index, vector<int>& candidates, vector<int> curr, int sum, int target){
        if (sum == target) res.push_back(curr);
        if (sum >= target) return;
        for (int i = index; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            helper(i, candidates, curr, sum + candidates[i], target);
            curr.pop_back();
        }
    }
};
