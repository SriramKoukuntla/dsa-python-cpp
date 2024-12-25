#https://leetcode.com/problems/minimum-absolute-difference/description/
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minDiff = float("inf")
        for i, value in enumerate (arr):
            if (i == 0):
                continue
            minDiff = min(minDiff, abs(arr[i]-arr[i-1]))
        ret = []
        for i, value in enumerate(arr):
            if (i == 0):
                continue
            if (abs(arr[i]-arr[i-1]) == minDiff):
                ret.append([arr[i-1], arr[i]])
        return ret