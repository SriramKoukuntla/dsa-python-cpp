#https://leetcode.com/problems/word-search/description/
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, ptr):
            if ptr == len(word):
                return True
            elif i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or (i, j) in visited or board[i][j] != word[ptr]:
                return False
            else:
                visited.add((i, j))
                res = dfs(i+1, j, ptr+1) or dfs(i-1, j, ptr+1) or dfs(i, j+1, ptr+1) or dfs(i, j-1, ptr+1)
                visited.remove((i, j))
                return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                visited = set()
                if dfs(i, j, 0): return True
        return False

