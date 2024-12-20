#https://leetcode.com/problems/3sum/
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        ret = []
        for i, value in enumerate(nums):
            if (i >= len(nums)-2):
                break
            if (i != 0 and nums[i] == nums[i-1]):
                continue
            l = i + 1
            r = len(nums)-1
            while (l < r):
                if (nums[i] + nums[l] + nums[r] == 0):
                    if len(ret) == 0:
                        ret.append([nums[i], nums[l], nums[r]])
                    elif ret[-1] != [nums[i], nums[l], nums[r]]:
                        ret.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                elif (nums[i] + nums[l] + nums[r] < 0):
                    l += 1
                else:
                    r -= 1
        return ret