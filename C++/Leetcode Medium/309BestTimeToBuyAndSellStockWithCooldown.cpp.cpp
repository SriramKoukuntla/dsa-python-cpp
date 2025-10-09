class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for (int i = 1; i < prices.size(); ++i){
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;
            hold = max(prevHold, prevRest-prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sold, hold);
    }
};  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mem(prices.size() + 2, 0);
        mem[prices.size()-1] = 0;
        for(int i = prices.size()-1; i >= 0; --i){
            int maxProfit = mem[i+1];
            for (int j = i+1; j < prices.size(); ++j){
                // cout << prices[j]-prices[i] << endl;
                maxProfit = max(maxProfit, prices[j]-prices[i] + mem[j+2]);
            }
            mem[i] = maxProfit;
        }
        return mem[0];
    }
};