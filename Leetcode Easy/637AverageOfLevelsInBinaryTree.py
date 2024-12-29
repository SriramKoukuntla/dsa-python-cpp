#https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        levels = []
        def helper(node, level):
            if node == None:
                return
            if len(levels) == level:
                levels.append([node.val, 1])
            else:
                levels[level][0] += node.val
                levels[level][1] += 1
            helper(node.left, level+1)
            helper(node.right, level+1)
        helper(root, 0)
        average = [0 for __ in range(len(levels))]
        for i, value in enumerate(levels):
            average[i] = value[0] / value[1]
        return average