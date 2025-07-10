#https://leetcode.com/problems/daily-temperatures/
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ret = [0 for __ in range(len(temperatures))]
        stack = [] #Stores (temperature, index)
        for i in range(len(temperatures)):
            while len(stack) != 0 and stack[-1][0] < temperatures[i]:
                temperature, index = stack.pop()
                ret[index] = i-index
            stack.append((temperatures[i], i))
        return ret