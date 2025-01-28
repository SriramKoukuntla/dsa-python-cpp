#https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            m = (l + r)//2
            if nums[l] <= nums[m]:#left side is sorted
                if nums[l] <= target and target <= nums[m]:
                    r = m
                else:
                    l = m + 1
            else: #right side is sorted
                if nums[m] <= target and target <= nums[r]:
                    l = m
                else:
                    r = m - 1
        return l if nums[l] == target else -1