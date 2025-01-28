#https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ret = float("-inf")
        stack = [] #(height, index)
        for i in range(len(heights)):
            start = i
            while len(stack) != 0 and stack[-1][0] > heights[i]:
                height, index = stack.pop()
                ret = max(ret, (i-index)*height)
                start = index
            stack.append((heights[i], start))
        for height, index in stack:
            ret = max(ret, (len(heights)-index)*height)
        return ret