#https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1366543262/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        current = root
        while current:
            if current.val == val:
                return current
            elif val > current.val:
                current = current.right
            else:
                current = current.left
        return None