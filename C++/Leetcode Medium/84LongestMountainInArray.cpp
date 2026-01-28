#include <vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int l = i-1;
            int r = i+1;
            if (!(l >= 0  && arr[l] < arr[l+1] && r < arr.size() && arr[r-1] > arr[r])) continue;

            while ((l >= 0  && arr[l] < arr[l+1]) || (r < arr.size() && arr[r-1] > arr[r])) {
                if (l >= 0  && arr[l] < arr[l+1]) --l;
                if (r < arr.size() && arr[r-1] > arr[r]) ++r;
            }
            res = max(res, r-l+1-2);
        }   
        return res < 3 ? 0 : res;
    }
};