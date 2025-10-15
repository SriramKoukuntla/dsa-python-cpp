#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        while (true){
            if (idx + nums[idx] >= nums.size()-1) return true;
            if (nums[idx] == 0) return false;

            int range = 0;
            int idxJump;

            for (int i = idx; i < idx + nums[idx] + 1; ++i){
                if (i + nums[i] >= range){
                    range = i + nums[i];
                    idxJump = i;
                }
            }

            idx = idxJump;
        }
        return true; 

    }
};