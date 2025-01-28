#https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            m = (l+r)//2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        return nums[l]


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            if r - l <= 1:
                return min(nums[r], nums[l])
            if nums[l] < nums[r]:
                return nums[l]
            m = (l + r)//2
            if nums[l] < nums[m]:
                l = m
            else:
                r = m

        #1, 2, 3, 4, 5
        #2, 3, 4, 5, 1
        #3, 4, 5, 1, 2
        #4, 5, 1, 2, 3
        #5, 1, 2, 3, 4
