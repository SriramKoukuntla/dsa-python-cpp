#https://leetcode.com/problems/single-number/description/
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        sum = 0
        for i, value in enumerate(nums):
            sum ^= value
        return sum