#https://leetcode.com/problems/minimum-absolute-difference/description/
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        ret = []
        minDistance = float("inf")
        for i in range(1, len(arr)):
            distance = arr[i] - arr[i-1]
            if distance == minDistance: ret.append([arr[i-1], arr[i]])
            if distance < minDistance:
                minDistance = distance
                ret = [[arr[i-1], arr[i]]]
        return ret