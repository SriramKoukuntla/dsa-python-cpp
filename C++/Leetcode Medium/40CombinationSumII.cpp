#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> temp;
        helper(candidates, combinations, temp, target, 0);
        return combinations;
    }

    void helper(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& temp, int target, int index) {
        if (target == 0) {
            combinations.push_back(temp);
            return;
        }

        if (index == candidates.size() || candidates[index] > target) return;

        //choose
        temp.push_back(candidates[index]);
        helper(candidates, combinations, temp, target-candidates[index], index+1);
        temp.pop_back();

        //not choose
        while (index != candidates.size()-1 && candidates[index] == candidates[index+1]) ++index;
        helper(candidates, combinations, temp, target, index+1);
    }
};

#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> temp;
        helper(candidates, combinations, temp, target, 0);
        return combinations;
    }

    void helper(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& temp, int target, int index) {
        if (index == candidates.size()) {
            if (target==0) combinations.push_back(temp);
            return;
        }

        if (candidates[index] > target) {
            helper(candidates, combinations, temp, target, candidates.size());
            return;
        }

        int nextIndex = candidates.size();
        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] != candidates[index]) {
                nextIndex = i;
                break;
            }
        }

        //don't choose branch
        helper(candidates, combinations, temp, target, nextIndex);

        //choose branch
        for (int i = index; i < nextIndex; ++i) {
            temp.push_back(candidates[index]);
            target -= candidates[i];
        }
        for (int i = index; i < nextIndex; ++i) {
            helper(candidates, combinations, temp, target, nextIndex);
            temp.pop_back();
            target += candidates[i];
        }
    }
};