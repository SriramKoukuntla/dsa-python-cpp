class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for (int pile : piles) r = max(r, pile);

        int res = r;
        while (l <= r) {
            int m = l + (r-l)/2;
            long time = 0;
            for (int pile : piles) {
                int temp = (pile+m-1)/m;
                time = time + temp;
            }
            if (time > h) l = m+1;
            else {
                res = m;
                r = m-1;
            }
        }
        return res;
    }
};