class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int res = 0;
        while (l < r) {
            int leftHeight = height[l];
            int rightHeight = height[r];
            int currVolume = min(leftHeight, rightHeight) * (r-l);
            res = max(res, currVolume);

            if (leftHeight < rightHeight) ++l;
            else --r;
        }

        return res;
    }
};

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int res = 0;
        while (l < r) {
            res = max(res, (r-l)*min(height[l], height[r]));
            if (height[l] > height[r]) --r;
            else ++l;
        }
        return res;
    }
};
