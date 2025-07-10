#https://leetcode.com/problems/validate-binary-search-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        ret = True
        def helper(node, maxVal, minVal):
            nonlocal ret
            if node == None: return
            if node.left != None:
                if node.left.val >= node.val or node.left.val <= minVal:
                    ret = False
                else: helper(node.left, node.val, minVal)
            if node.right != None:
                if node.right.val <= node.val or node.right.val >= maxVal:
                    ret = False
                else: helper(node.right, maxVal, node.val)
        helper(root, float("inf"), float("-inf"))
        return ret