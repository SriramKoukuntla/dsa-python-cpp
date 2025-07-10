#https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        area = min(height[left], height[right]) * (right-left)
        while left < right:
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
            tempArea = min(height[left], height[right]) * (right-left)
            area = max(area, tempArea)
        return area


class Solution:
    def maxArea(self, height: List[int]) -> int:
        area = 0
        for left in range(len(height)):
            for right in range(len(height)):
                tempArea = min(height[left], height[right]) * (right-left)
                area = max(area, tempArea)
        return area 