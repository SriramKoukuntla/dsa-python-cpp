#https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#Recursive Solution
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        elements = []
        def helper(node):
            if node == None: return
            helper(node.left)
            elements.append(node.val)
            helper(node.right)
        helper(root)
        return elements[k-1]
#Iterative Solution
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        curr = root
        while curr != None or len(stack) > 0:
            if curr != None:
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack.pop()
                k -= 1
                if k == 0: return curr.val
                curr = curr.right