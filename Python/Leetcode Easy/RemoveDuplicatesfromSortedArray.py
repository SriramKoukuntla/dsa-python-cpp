#https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #counter is the back pointer
        #i is the front pointer
        counter = 0
        for i in range(1, len(nums)):
            if nums[counter] == nums[i]:
                continue
            else:
                counter += 1
                nums[counter] = nums[i]
        counter += 1
        return counter 