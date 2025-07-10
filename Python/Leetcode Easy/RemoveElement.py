#https://leetcode.com/problems/remove-element/
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        notValCounter = 0
        for i in range(0, len(nums)):
            if nums[i] == val:
                continue
            else:
                nums[notValCounter] = nums[i]
                notValCounter += 1
        return notValCounter