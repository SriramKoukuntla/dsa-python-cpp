#https://leetcode.com/problems/valid-sudoku/description/
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        temp = [False for __ in range(10)]
        #Checking if each row is valid
        for row in board:
            for entry in row:
                if entry.isnumeric():
                    number = int(entry)
                    if temp[number]:
                        return False
                    else:
                        temp[number] = True
                else:
                    continue
            temp = [False for __ in range(10)] 
        #Checking if each column is valid
        for j, entry in enumerate(board[0]):
            for i, row in enumerate(board):
                string = board[i][j]
                if string.isnumeric():
                    number = int(string)
                    if temp[number]:
                        return False
                    else:
                        temp[number] = True
            temp = [False for __ in range(10)] 

        #checking each square
        points = [(0, 3), (3, 6), (6, 9)]
        for i, point in enumerate(points):
            for j, point2 in enumerate(points):
                for z in range(point[0], point[1]):
                    for d in range(point2[0], point2[1]):
                        string = board[z][d]
                        if string.isnumeric():
                            number = int(string)
                            if temp[number]:
                                return False
                            else:
                                temp[number] = True
                temp = [False for __ in range(10)] 

        return True