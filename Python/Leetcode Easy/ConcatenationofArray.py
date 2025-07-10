#https://leetcode.com/problems/concatenation-of-array/description/
class Solution(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for j in range(2):
            for i in range(len(nums)):
                ans.append(nums[i])
        return ans