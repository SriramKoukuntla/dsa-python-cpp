#https://leetcode.com/problems/maximum-subarray/description/
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        curSum, maxSum = 0, nums[0]
        for num in nums:
            curSum = max(curSum, 0)
            curSum += num
            maxSum = max(curSum, maxSum)
        return maxSum