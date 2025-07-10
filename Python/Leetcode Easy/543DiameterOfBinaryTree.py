#https://leetcode.com/problems/diameter-of-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        def helper(node):
            if node == None: return 0
            left = helper(node.left)
            right = helper(node.right)
            self.res = max(self.res, left + right)
            return 1 + max(left, right)
        helper(root)
        return self.res