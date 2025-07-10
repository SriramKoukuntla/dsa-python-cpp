#https://leetcode.com/problems/max-area-of-island/description/
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        currCount = 0
        def helper(i, j):
            nonlocal currCount
            if grid[i][j] == 0: return
            if grid[i][j] == 1:
                currCount += 1
                grid[i][j] = 0
            if i != 0: helper(i-1, j)
            if i != len(grid)-1: helper(i+1, j)
            if j != 0: helper(i, j-1)
            if j != len(grid[0])-1: helper(i, j+1)
        
        
        
        maxRet = 0
        for i, row in enumerate(grid):
            for j, entry in enumerate(row):
                if grid[i][j] == 1:
                    helper(i, j)
                    maxRet = max(maxRet, currCount)
                    currCount = 0
        return maxRet