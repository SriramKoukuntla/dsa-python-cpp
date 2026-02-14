#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int biggestLeftElement = height[l];
        int biggestRightElement = height[r];
        int res = 0;

        while (l+1 < r) {
            if (height[l] <= height[r]) {
                ++l;
                int currHeight = height[l];
                res += max(0, min(biggestLeftElement, biggestRightElement)-currHeight);
                biggestLeftElement = max(biggestLeftElement, currHeight);
            }
            else {
                --r;
                int currHeight = height[r];
                res += max(0, min(biggestLeftElement, biggestRightElement)-currHeight);
                biggestRightElement = max(biggestRightElement, currHeight);
            }
        }
        return res;
    }
};