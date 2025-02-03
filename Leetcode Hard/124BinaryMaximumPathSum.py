#https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxRet = float('-inf')
        def helper(node):
            nonlocal maxRet
            if node == None:
                return 0
            left, right = helper(node.left), helper(node.right)
            temp = max(node.val, max(node.val + left, node.val + right))
            maxRet = max(maxRet, max(temp, node.val + left + right))
            return temp
        helper(root)
        return maxRet

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxRet = float('-inf')
        def helper(node):
            nonlocal maxRet
            if node == None:
                return None
            if node.left == None and node.right == None:
                maxRet = max(maxRet, node.val)
                return node.val
            if node.left != None and node.right == None:
                left = helper(node.left)
                temp = max(node.val, node.val+left)
                maxRet = max(maxRet, temp)
                return temp
            if node.left == None and node.right != None:
                right = helper(node.right)
                temp = max(node.val, node.val+right)
                maxRet = max(maxRet, temp)
                return temp
            if node.left != None and node.right != None:
                left, right = helper(node.left), helper(node.right)
                temp = max(node.val, max(node.val + left, node.val + right))
                maxRet = max(maxRet, max(temp, node.val + left + right))
                return temp
        helper(root)
        return maxRet