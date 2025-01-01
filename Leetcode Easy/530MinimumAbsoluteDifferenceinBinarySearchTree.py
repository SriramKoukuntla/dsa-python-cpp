#https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        arr = []
        def helper(node):
            if node == None: return
            helper(node.left)
            nonlocal arr
            arr.append(node.val)
            helper(node.right)
        helper(root)
        minDiff = float("inf")
        ret = []
        for i in range(1, len(arr)):
            diff = arr[i] - arr[i-1]
            minDiff = min(diff, minDiff)
        return minDiff