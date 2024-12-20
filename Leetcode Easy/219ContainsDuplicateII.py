#https://leetcode.com/problems/contains-duplicate-ii/description/
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        window = set()
        L = 0
        for R in range(len(nums)):
            if R - L  > k:
                window.remove(nums[L])
                L += 1
            if nums[R] in window:
                return True
            window.add(nums[R])
        return False
    
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        tracker = {}
        for i, value in enumerate(nums):
            if value not in tracker:
                tracker[value] = [i]
            else:
                for index in tracker[value]:
                    if (abs(index-i) <= k):
                        return True
                tracker[value].append(i)
        return False
            
            