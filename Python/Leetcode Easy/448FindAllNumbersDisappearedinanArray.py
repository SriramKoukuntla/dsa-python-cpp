#https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ret = []
        numsSet = set(nums)
        for number in range(1, len(nums)+1):
            if not number in numsSet:
                ret.append(number)
        return ret