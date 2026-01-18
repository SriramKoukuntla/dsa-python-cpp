#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int forward = 1;
        int backward = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] *= forward;
            res[res.size()-1-i] *= backward;
            forward *= nums[i];
            backward *= nums[nums.size()-1-i];
        }
        return res;        
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //1, 2, 3, 4
        //1, 1, 2, 6
        //24, 12, 4, 1
        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            forward[i] = forward[i-1] * nums[i-1];
            backward[nums.size()-1-i] = backward[nums.size()-1-i+1] * nums[nums.size()-1-i+1];
        }
        vector<int> res;
        for (int i = 0; i < forward.size(); ++i) {
            res.push_back(forward[i] * backward[i]);
        }
        return res;
    }
};