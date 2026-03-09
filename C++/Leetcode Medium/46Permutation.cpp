class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, int idx) {
        if (idx == nums.size()-1) return {{nums[idx]}};
        int firstNumber = nums[idx];
        const vector<vector<int>>& subproblemPermutations = helper(nums, idx+1);    
        vector<vector<int>> res;
        for (int i = 0; i < subproblemPermutations.size(); ++i) {
            vector<int> subproblemPermutation = subproblemPermutations[i];
            for (int j = 0; j <= subproblemPermutation.size(); ++j) {
                vector<int> tempPermutation(subproblemPermutation.begin(), subproblemPermutation.begin()+j);
                tempPermutation.push_back(firstNumber);
                tempPermutation.insert(tempPermutation.end(), subproblemPermutation.begin()+j, subproblemPermutation.end());
                res.push_back(tempPermutation);
            }
        }
        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums, 0);
    }
};


#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        vector<vector<int>> res;
        helper(used, used.size(), temp, res, nums);
        return res;
    }

    void helper(vector<bool>& used, int left, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums) {
        if (left == 0) res.push_back(temp);
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            --left;
            helper(used, left, temp, res, nums);
            temp.pop_back();
            used[i] = false;
            ++left;
        }
    }
};

//Backtracking Solution
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        permuteHelper(nums, temp);
        return res;
    }
private:
    void permuteHelper(vector<int>& remainingNums, vector<int>& temp){
        if (remainingNums.size() == 0) {
            res.push_back(temp);
        }
        for (int i = 0; i < remainingNums.size(); ++i){
            temp.push_back(remainingNums[i]);
            vector<int> remainingNumsTemp;
            remainingNumsTemp.insert(remainingNumsTemp.end(), remainingNums.begin(), remainingNums.begin() + i);
            remainingNumsTemp.insert(remainingNumsTemp.end(), remainingNums.begin() + i + 1, remainingNums.end());
            permuteHelper(remainingNumsTemp, temp);
            temp.pop_back();
        }
    }
};


//DFS Solution
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums, {});
        return res;
    }
private:
    void permuteHelper(vector<int>& remainingNums, vector<int> temp){
        if (remainingNums.size() == 0) res.push_back(temp);
        for (int i = 0; i < remainingNums.size(); ++i){
            temp.push_back(remainingNums[i]);
            vector<int> remainingNumsTemp;
            remainingNumsTemp.insert(remainingNumsTemp.end(), remainingNums.begin(), remainingNums.begin() + i);
            remainingNumsTemp.insert(remainingNumsTemp.end(), remainingNums.begin() + i + 1, remainingNums.end());
            permuteHelper(remainingNumsTemp, temp);
            temp.pop_back();
        }
    }
};