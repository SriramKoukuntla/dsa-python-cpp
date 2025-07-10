#https://leetcode.com/problems/maximum-subarray/description/
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        larSum = float('-inf')
        currSum = 0
        for i, value in enumerate(nums):
            currSum += nums[i]
            larSum = max(larSum, currSum)
            if currSum < 0:
                currSum = 0
        return larSum