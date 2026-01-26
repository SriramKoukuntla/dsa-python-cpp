#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        vector<int> curr = points[0];
        for (int i = 1; i < points.size(); ++i) {
            vector<int> dst = points[i];
            res += max(abs(dst[0]-curr[0]), abs(dst[1]-curr[1]));
            curr = dst;
        }
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        vector<int> curr = points[0];
        for (int i = 1; i < points.size(); ++i) {
            vector<int> dst = points[i];
            while (curr[0] != dst[0] || curr[1] != dst[1]) {
                if (curr[0] < dst[0]) ++curr[0];
                if (curr[0] > dst[0]) --curr[0];
                if (curr[1] < dst[1]) ++curr[1];
                if (curr[1] > dst[1]) --curr[1];
                ++res;
            }
        }
        return res;
    }
};