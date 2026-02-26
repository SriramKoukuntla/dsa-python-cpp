class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];

        int res = 0;
        while (left < right-1) {
            int minBoundaryHeight = min(maxLeftHeight, maxRightHeight);
            int leftRightCurr = height[left+1];
            int rightLeftCurr = height[right-1];
            int leftCurr = height[left];
            int rightCurr = height[right];
            if (leftCurr <= rightCurr) {
                maxLeftHeight = max(maxLeftHeight, leftRightCurr);
                res += max(0, minBoundaryHeight-leftRightCurr);
                ++left;
            }
            else {
                maxRightHeight = max(maxRightHeight, rightLeftCurr);
                res += max(0, minBoundaryHeight-rightLeftCurr);
                --right;
            }
        }
        return res;
    }
};

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