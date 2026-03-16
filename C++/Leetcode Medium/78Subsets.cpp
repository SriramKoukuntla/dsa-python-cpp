class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res; 
    }
};
//Initialize res array as a singular empty {{}}
//For each element in nums, grab each array in res that existed before the iteration started, and create a new temporary vector which is res[j] + nums[i] and put it onto res
//return res;

//{[]}
//{[], [1]}
//{[2], [1, 2]} -> {[], [1], [2], [1, 2]}
//{[], [1], [2], [1, 2]} -> 
//{ -> {[], [1], [2], [1, 2], [3], [1, 4], [2, 3], [1, 2, 3]} 

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for(int j = 0; j < n; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums){
            int size = res.size();
            for (int i = 0; i < size; ++i){
                vector<int> temp = res[i];
                temp.push_back(num);
                res.push_back(temp);
            }
        } 
        return res;
    }
};