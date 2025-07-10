#https://leetcode.com/problems/search-in-a-binary-search-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#Iterative Solution
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        curr = root
        while curr != None:
            if curr.val == val: return curr
            if val < curr.val: curr = curr.left
            else: curr = curr.right
        return None
#Recursive Solution
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        def helper(node):
            if node == None: return
            if node.val == val: return node
            if val > node.val: return helper(node.right)
            else: return helper(node.left)
        return  helper(root)