#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Range of possible days
        int l = 1;
        int r = -1;
        for (int num : bloomDay) r = max(r, num);

        //Finding numDays to make m bouquets
        int res = -1;
        while (l <= r) {
            int currDay = l + (r-l)/2;
            int bouquetsMade = 0;
            int adjFlowers = 0;
            for (int i = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] > currDay) adjFlowers = 0;
                else {
                    if (++adjFlowers == k) {
                        ++bouquetsMade;
                        adjFlowers = 0;
                    }
                }
            }
            if (bouquetsMade >= m) {
                res = currDay;
                r = currDay-1;
            }
            else l = currDay+1;
        }

        return res;
    }
};