#https://leetcode.com/problems/sort-colors/
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        numbers = [0, 0, 0]
        for i in range(len(nums)):
            numbers[nums[i]] += 1
        #Counting how many of each color
        index = 0
        for i in range(len(numbers)):
            for j in range(numbers[i]):
                nums[index] = i
                index += 1
        #replacing same nums array