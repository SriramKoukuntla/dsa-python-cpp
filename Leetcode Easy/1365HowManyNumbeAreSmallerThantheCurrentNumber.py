#https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        sortedNums = sorted(nums)
        dictionary = {}
        for i, v in enumerate(sortedNums):
            if not v in dictionary:
                dictionary[v] = i
        ret = []
        for num in nums:
            ret.append(dictionary[num])
        return ret