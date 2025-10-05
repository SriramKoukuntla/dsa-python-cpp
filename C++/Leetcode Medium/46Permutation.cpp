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