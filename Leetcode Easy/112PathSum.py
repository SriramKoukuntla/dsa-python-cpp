#https://leetcode.com/problems/path-sum/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        sumCounter = 0
        if root == None: return False
        stack = [(root, root.val)]
        while len(stack) > 0:
            node, value = stack.pop()
            if node.left != None: stack.append((node.left, value + node.left.val))
            if node.right != None: stack.append((node.right, value + node.right.val))
            if node.left == None and node.right == None and value == targetSum: return True
        return False