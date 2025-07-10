#https://leetcode.com/problems/contains-duplicate/
# class Solution(object):
#     def containsDuplicate(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """
#         hashset = set()
#         for i in nums:
#             if i in hashset:
#                 return True
#             hashset.add(i)
#         return False

#Better way more compact
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)