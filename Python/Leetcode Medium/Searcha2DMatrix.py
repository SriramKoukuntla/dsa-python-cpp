#https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        rows, columns = len(matrix), len(matrix[0])
        size = rows * columns
        left, right = 0, size-1
        while left <= right:
            middle = (left + right)/2
            middleValue = matrix[middle / columns][middle % rows]
            if target < middleValue:
                right = middle-1
            elif target > middleValue:
                left = middle+1
            else:
                return True
        return False