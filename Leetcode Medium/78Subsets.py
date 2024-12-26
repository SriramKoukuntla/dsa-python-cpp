#https://leetcode.com/problems/subsets/description/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = [[]]
        for i in range(len(nums)):
            newSubSets = []
            for j, subSet in enumerate(ret):
                clonedSubset = ret[j][:]
                clonedSubset.append(nums[i])
                newSubSets.append(clonedSubset)
            ret += newSubSets
        return ret







# class Solution:
    # def subsets(self, nums: List[int]) -> List[List[int]]:
    #     ret = []
    #     def helper(subSet: List[int], i: int):
    #         if i == len(nums):
    #             ret.append(subSet[:])
    #             return
            
    #         helper(subSet, i+1)
    #         cloneSubSet = subSet[:] 
    #         cloneSubSet.append(nums[i])  
    #         helper(cloneSubSet, i + 1)
    #         return

    #     helper([], 0)
    #     return ret