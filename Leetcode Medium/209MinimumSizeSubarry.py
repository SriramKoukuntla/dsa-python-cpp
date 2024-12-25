#https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minCount = float('inf')
        left = 0
        sumCounter = 0
        for i, value in enumerate(nums):
            sumCounter += nums[i]
            while sumCounter >= target:
                minCount = min(minCount, i-left+1)
                sumCounter -= nums[left]
                left+=1 
        return 0 if minCount == float('inf') else minCount