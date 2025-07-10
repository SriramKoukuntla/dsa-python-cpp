#https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        maxProfit = 0
        currProfit = 0
        for right, price in enumerate(prices):
            currProfit = prices[right]-prices[left]
            if currProfit < 0:
                left = right
            maxProfit = max(currProfit, maxProfit)
        return maxProfit