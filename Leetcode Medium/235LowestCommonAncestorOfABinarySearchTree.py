#https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ancestorsP = {root: None} 
        ancestorsQ = {root: None}
        def ancestorGenerator(node, hashmap):
            curr = root
            while True:
                if curr == node: break
                if curr.val > node.val:
                    hashmap[curr.left] = curr
                    curr = curr.left
                else:
                    hashmap[curr.right] = curr
                    curr = curr.right
        ancestorGenerator(p, ancestorsP)
        ancestorGenerator(q, ancestorsQ)
        while True:
            if p in ancestorsQ: return p
            else: p = ancestorsP[p]