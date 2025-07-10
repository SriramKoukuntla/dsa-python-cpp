#https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        counter = 0
        def helper(node, maxNum):
            nonlocal counter
            if node == None: return
            if node.val >= maxNum:
                maxNum = node.val
                counter += 1
            helper(node.left, maxNum)
            helper(node.right, maxNum)
        helper(root, float('-inf'))
        return counter