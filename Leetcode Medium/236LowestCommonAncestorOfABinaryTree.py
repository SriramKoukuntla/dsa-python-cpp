#https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


#Recursive DFS Solution
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ret = None
        def helper(node):
            if node == None: return [False, False]
            left = helper(node.left)
            right = helper(node.right)
            middle = [left[0] or right[0], left[1] or right[1]]
            if node == p: middle[0] = True
            if node == q: middle[1] = True 
            if middle[0] and middle[1]:
                self.ret = node
                return [False, False]
            return middle
        helper(root)
        return self.ret
    
#More Simple Recursive DFS Solution
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or root == p or root == q: return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left != None and right != None: return root
        if left != None: return left
        else: return right