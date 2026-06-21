class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            //z
            //max(weights[i]) <= z <= sum(weights)
            int l = weights[0];
            for (int i = 1; i < weights.size(); ++i) l = max(l, weights[i]);
            int r = 0;
            for (int i = 0; i < weights.size(); ++i) r += weights[i];
            
            int res = r;
            while (l <= r) {
                int currRes = l + ((r-l)/2);
                int currWeight = 0;
                int currDay = 1;
                //How many flights for current maximum weight capacity
                for (int i = 0; i < weights.size(); ++i) {
                    //If current flight is too heavy, add new flight
                    if (currWeight + weights[i] > currRes) {
                        currWeight = 0;
                        ++currDay;
                    }
                    currWeight += weights[i];
                }
                if (currDay > days) l = currRes + 1;
                else {
                    res = min(res, currRes);
                    r = currRes - 1;
                }
            }
            return res; 
        }
    };