#https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        maxDepth = 0
        stack = [[root, 1]]
        while len(stack) > 0:
            node, level = stack.pop()
            if node == None: continue
            maxDepth = max(maxDepth, level)
            stack.append([node.left, level+1])
            stack.append([node.right, level+1])
        return maxDepth