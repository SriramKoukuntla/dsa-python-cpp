#https://leetcode.com/problems/number-of-islands/description/
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i, j):
            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == "0":
                return
            else:
                grid[i][j] = "0"
                dfs(i+1, j)
                dfs(i-1, j)
                dfs(i, j+1)
                dfs(i, j-1)
        counter = 0
        for i, row in enumerate(grid):
            for j, land in enumerate(row):
                if land == "1":
                    counter += 1
                    dfs(i, j)
                    grid[i][j] = "0"
        return counter
