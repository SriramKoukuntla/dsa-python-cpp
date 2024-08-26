#https://leetcode.com/problems/two-sum/submissions/1367483054/
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for i in range(len(nums)):
            wanted = target - nums[i]
            if wanted in hashmap:
                return [i, hashmap[wanted]]
            hashmap[nums[i]] = i       
        return [-1]