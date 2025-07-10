#https://leetcode.com/problems/letter-case-permutation/description/
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ret = [s]
        for i in range(len(s)):
            if s[i].isalpha():
                tempRet = []
                for j, value in enumerate(ret):
                    tempRet.append(ret[j][0:i] + ret[j][i].lower() + ret[j][i+1:])
                    tempRet.append(ret[j][0:i] + ret[j][i].upper() + ret[j][i+1:])
                ret = tempRet
        return ret
    

# class Solution:
#     def letterCasePermutation(self, s: str) -> List[str]:
#         ret = []
#         def helperFunction(s: str, i: int):
#             if i >= len(s):
#                 ret.append(s)
#                 return
#             if s[i:i+1].isalpha():
#                 helperFunction(s[0:i] + s[i:i+1].upper() + s[i+1:], i+1)
#                 helperFunction(s[0:i] + s[i:i+1].lower() + s[i+1:], i+1)
#             else:
#                 helperFunction(s, i+1)
#             return
#         helperFunction(s, 0)
#         return ret