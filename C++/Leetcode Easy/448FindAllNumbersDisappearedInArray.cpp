#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> appears(nums.size(), false);
        for (int n : nums) appears[n-1] = true;
        vector<int> res;
        for (int i = 0; i < appears.size(); ++i) if (!appears[i]) res.push_back(i+1);
        return res;
    }
};