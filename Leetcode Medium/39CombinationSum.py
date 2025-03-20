class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        temp = []
        for i in range(len(candidates)):
            if candidates[i] <= target:
                temp.append(candidates[i])
        candidates = list(set(temp))

        ret = []

        Sum = 0
        temp = []
        def helper(i):
            nonlocal Sum
            if i >= len(candidates):
                return
            if Sum == target:
                ret.append(temp[:])
                return
            elif Sum > target:
                return
            elif Sum < target:
                Sum += candidates[i]
                temp.append(candidates[i])
                helper(i)
                Sum -= candidates[i]
                temp.pop()
                helper(i+1)
        helper(0)
        return ret