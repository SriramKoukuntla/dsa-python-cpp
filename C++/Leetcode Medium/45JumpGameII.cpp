#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int idx = 0;
        while (true){
            if (idx == nums.size()-1) return jumps;
            if (idx + nums[idx] >= nums.size()-1) return jumps+1;
            
            int idxJump;
            int range = 0;
            for (int i = idx; i < idx + nums[idx]+1; ++i){
                if (i + nums[i] >= range){
                    range = i + nums[i];
                    idxJump = i;
                }
            }
            idx = idxJump;
            ++jumps;
        }
    }
};