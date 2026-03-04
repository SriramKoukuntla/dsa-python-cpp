#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) swap(nums1, nums2);
        vector<int>& bigger = nums1;
        vector<int>& smaller = nums2;

        int total = smaller.size() + bigger.size();
        int half = total/2;

        int l = -1; int r = smaller.size()-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            int m2 = (half-(m+1))-1;

            int smallerLeft = (m < 0) ? INT_MIN : smaller[m];
            int smallerRight = (m+1 == smaller.size()) ? INT_MAX : smaller[m+1];


            int biggerLeft = (m2 < 0) ? INT_MIN : bigger[m2];
            int biggerRight = (m2+1 == bigger.size()) ? INT_MAX : bigger[m2+1];

            if (smallerLeft <= biggerRight && biggerLeft <= smallerRight) {
                if (total % 2 == 1) return min(smallerRight, biggerRight);
                else return (max(smallerLeft, biggerLeft) + min(smallerRight, biggerRight))/2.0;
            }
            else if (smallerLeft > biggerRight) r = m-1;
            else l = m+1;
        }

        cout << "SHOULD NOT RUN" << endl;
        return -1;
    }
};