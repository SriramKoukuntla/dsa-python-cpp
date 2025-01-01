#https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.values = set()
        self.ret = False
        def helper(node):
            if node == None: return
            if k-node.val in self.values:
                self.ret = True
                return
            self.values.add(node.val)
            helper(node.left)
            helper(node.right)
        helper(root)
        return self.ret