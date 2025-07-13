#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resProfit = 0;
        int buyIdx = 0;
        for (int sellIdx = 0; sellIdx < prices.size(); ++sellIdx){
            int buyPrice = prices[buyIdx];
            int sellPrice = prices[sellIdx];
            int currProfit = sellPrice - buyPrice;
            if (currProfit > resProfit) resProfit = currProfit;
            if (sellPrice < buyPrice) buyIdx = sellIdx;
        }
        return resProfit;        
    }
};