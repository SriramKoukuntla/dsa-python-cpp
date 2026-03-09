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