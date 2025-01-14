#https://leetcode.com/problems/longest-consecutive-sequence/
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numsSet = set(nums)
        maxCounter = 0
        for num in nums:
            if num not in numsSet:
                continue
            tempCounter = 0
            curr = num
            while curr+1 in numsSet:
                tempCounter += 1
                curr += 1
                numsSet.remove(curr)
            curr = num
            while curr-1 in numsSet:
                tempCounter+=1 
                curr-=1 
                numsSet.remove(curr)
            maxCounter = max(maxCounter, tempCounter+1)
        return maxCounter