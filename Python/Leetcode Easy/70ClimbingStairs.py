#https://leetcode.com/problems/climbing-stairs/description/
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        elif n == 2:
            return 2

        tabArr = [0 for i in range(n+1)]
        tabArr[0] = 1
        tabArr[1] = 1
        tabArr[2] = 2
        for i in range(3, n+1):
            tabArr[i] = tabArr[i-1] + tabArr[i-2]
        return tabArr[-1]