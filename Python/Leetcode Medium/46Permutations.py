#https://leetcode.com/problems/permutations/description/
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ret = []
        def helper(subset: List[int], remaining: List[int]):
            if len(remaining) == 0:
                ret.append(subset)
                return
            for i, value in enumerate(remaining):
                copySubSet = subset[:]
                copySubSet.append(value)
                copyRemaining = remaining[:]
                copyRemaining.pop(i)
                helper(copySubSet, copyRemaining)
        helper([], nums)
        return ret

#Back tracking method  
# class Solution:
#     def permute(self, nums: List[int]) -> List[List[int]]:
#         ret = []
#         def helper(subset: List[int], remaining: List[int]):
#             if len(remaining) == 0:
#                 ret.append(subset[:])
#                 return
#             for i, value in enumerate(remaining):
#                 subset.append(value)
#                 temp = remaining.pop(i)
#                 helper(subset, remaining)
#                 subset.pop()
#                 remaining.insert(i, temp)
#         helper([], nums)
#         return ret