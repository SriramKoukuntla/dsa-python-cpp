#https://leetcode.com/problems/minimum-time-visiting-all-points/description/
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        time = 0
        x1, y1 = points.pop()
        while points:
            x2, y2 = points.pop()
            time += max(abs(x2-x1), abs(y2-y1))
            x1, y1 = x2, y2
        return time