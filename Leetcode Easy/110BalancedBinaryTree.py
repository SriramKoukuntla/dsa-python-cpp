#https://leetcode.com/problems/balanced-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        ret = True
        def helper(node):
            if node == None: return 0
            left = helper(node.left)
            right = helper(node.right)
            nonlocal ret
            if abs(left-right) > 1: ret = False
            return max(left, right) + 1
        helper(root)
        return ret