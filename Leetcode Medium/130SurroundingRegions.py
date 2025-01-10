#https://leetcode.com/problems/surrounded-regions/description/
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def helper(i, j):
            if i < 0 or j < 0 or i == len(board) or j == len(board[0]): return
            if board[i][j] == "X" or board[i][j] == "T": return
            if board[i][j] == "O":
                board[i][j] = "T"
                helper(i-1, j)
                helper(i, j-1)
                helper(i+1, j)
                helper(i, j+1)
        for i, entry in enumerate(board[0]):
            helper(0, i)
            helper(len(board)-1, i)
        for j, row in enumerate(board):
            helper(j, 0)
            helper(j, len(board[0])-1)
        for i, row in enumerate(board):
            for j, entry in enumerate(row):
                if board[i][j] == "O": board[i][j] = "X"
                if board[i][j] == "T": board[i][j] = "O"