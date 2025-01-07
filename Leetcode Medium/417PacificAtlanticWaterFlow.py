#https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        reachable = {(0, len(heights[0])-1): True, (len(heights)-1, 0): True}
        pacificReachable, atlanticReachable = False, False
        visited = set()
        def helper(i, j):
            nonlocal pacificReachable, atlanticReachable, reachable
            if (i, j) in reachable: pacificReachable, atlanticReachable = True, True
            if (i, j) in visited: return
            if pacificReachable and atlanticReachable: return
            visited.add((i, j))
            if i == 0 or j == 0:
                pacificReachable = True
            if i == len(heights)-1 or j == len(heights[0])-1:
                atlanticReachable = True
            if i != 0 and heights[i][j] >= heights[i-1][j]:
                helper(i-1, j)
            if j != 0 and heights[i][j] >= heights[i][j-1]:
                helper(i, j-1)
            if i != len(heights)-1 and heights[i][j] >= heights[i+1][j]:
                helper(i+1, j)
            if j != len(heights[0])-1 and heights[i][j] >= heights[i][j+1]:
                helper(i, j+1)
                        

        ret = []
        for i, row in enumerate(heights):
            for j, value in enumerate(row):
                helper(i, j)
                if pacificReachable and atlanticReachable:
                    ret.append((i, j))
                    reachable[(i, j)] = True
                pacificReachable, atlanticReachable = False, False
                visited = set()
        return ret