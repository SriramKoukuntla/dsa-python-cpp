#https://leetcode.com/problems/coin-change/description/
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        tabArr = [float('inf') for i in range(amount+1)]
        tabArr[0] = 0
        for i in range(1, amount+1):
            for coin in coins:
                if i - coin >= 0 and tabArr[i-coin] != -1:
                    tabArr[i] = min(tabArr[i], tabArr[i-coin]+1)
            if tabArr[i] == float('inf'):
                tabArr[i] = -1
        return tabArr[-1]