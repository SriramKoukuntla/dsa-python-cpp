#https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        queue = deque([(root, 1)])
        while True:
            node, level = queue.popleft()
            if node == None: continue
            if node.left == None and node.right == None: return level
            queue.append((node.left, level+1))
            queue.append((node.right, level+1))
        
