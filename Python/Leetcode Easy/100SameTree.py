#https://leetcode.com/problems/same-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue = deque([(p, q)])
        while len(queue) > 0:
            first, second = queue.popleft()
            if (first == None and second != None) or (first != None and second == None): return False
            if first == None and second == None: continue
            if first.val != second.val: return False
            queue.append((first.left, second.left))
            queue.append((first.right, second.right))
        return True