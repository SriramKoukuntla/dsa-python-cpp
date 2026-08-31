#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        for (int i = 0; i < nums.size(); ++i) ans.push_back(nums[i]);
        return ans;
    }
};

class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            vector<int> ans = nums;
            for (int num : nums) ans.push_back(num);
            return ans;
        }
    };

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};