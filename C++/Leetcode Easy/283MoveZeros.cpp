class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Identify next zero (j position)
        //Find next non zero after j (i position)
        //Swap
        int i = -1;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0) {
                i = max(i, j+1);
                while (i < nums.size() && nums[i] == 0) ++i;
                if (i == nums.size()) return;
                swap(nums[j], nums[i]);
                ++i;
            }
        }
    }
};
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool swapOccurred = true;
        while (swapOccurred) {
            swapOccurred = false;
            for (int i = 0; i < nums.size()-1; ++i) {
                if (nums[i] == 0 && nums[i+1] != 0) {
                    swap(nums[i], nums[i+1]);
                    swapOccurred = true;
                }
            }
        }
    }
};