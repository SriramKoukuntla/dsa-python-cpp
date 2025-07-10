#https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        L, total, length = 0, 0, float("inf")
        for R in range(len(nums)):
            total += nums[R]
            while total >= target:
                length = min(length, R-L+1) 
                total -= nums[L]
                L += 1
        return 0 if length == float("inf") else length