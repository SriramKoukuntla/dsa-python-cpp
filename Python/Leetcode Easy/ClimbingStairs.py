#https://leetcode.com/problems/climbing-stairs/description/
#Recursive Solution
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        sol = []
        sol.append(0) #index 0 has 0
        sol.append(1) #index 1 has 1
        sol.append(2) #index 2 has 1
        if n < 3:
            return sol[n]
        else:
            for i in range(3, n+1):
                sol.append(sol[i-2] + sol[i-1])
            return sol[n]
#DP Solution
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        sol = []
        sol.append(0) #index 0 has 0
        sol.append(1) #index 1 has 1
        sol.append(2) #index 2 has 1
        if n < 3:
            return sol[n]
        else:
            for i in range(3, n+1):
                sol.append(sol[i-2] + sol[i-1])
            return sol[n]