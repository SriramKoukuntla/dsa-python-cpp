#https://leetcode.com/problems/subsets/description/


#How it should be solved. Explain the tree of decisions when doing this problem in an interivew.
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = [] #[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3]
        temp = []
        def helper(i):
            if i == len(nums):
                ret.append(temp[:])
                return
            temp.append(nums[i])
            helper(i+1)
            temp.pop()
            helper(i+1)
        helper(0)
        return ret
    



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