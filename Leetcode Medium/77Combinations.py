#https://leetcode.com/problems/combinations/description/
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        def helper(subset: List[int], i: int): #i = current int we are on
            if len(subset) == k:
                copy = subset[:]
                ret.append(copy)
                return
            if len(subset) + n-i + 1 < k:
                return
            for j in range(i, n+1):
                subset.append(j)
                helper(subset, j+1)
                subset.pop()
        helper([], 1)
        return ret


# class Solution:
#     def combine(self, n: int, k: int) -> List[List[int]]:
#         ret = []
#         def helper(subset: List[int], i: int): #i = current int we are on
#             if len(subset) == k:
#                 ret.append(subset)
#                 return
#             if i > n:
#                 return
#             for j in range(i, n+1): #Going backwards
#                 copy = subset[:]
#                 copy.append(j)
#                 helper(copy, j+1)
#         helper([], 1)
#         return ret
    

# class Solution:
#     def combine(self, n: int, k: int) -> List[List[int]]:
#         ret = [[]]
#         for i in range(1, n + 1):
#             temp = []
#             for j, subset in enumerate(ret):
#                 temp.append(subset)
#                 if len(subset) != k:
#                     newSet = subset[:]
#                     newSet.append(i)
#                     temp.append(newSet)
#             ret = temp
#         newRet = []
#         for subset in ret:
#             if len(subset) == k:
#                 newRet.append(subset)
#         return newRet
