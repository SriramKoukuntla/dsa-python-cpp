#https://leetcode.com/problems/binary-tree-level-order-traversal/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ret = []
        queue = deque([(root, 0)])
        while len(queue) > 0:
            node, level = queue.popleft()
            if node == None: continue
            if len(ret) == level: ret.append([node.val])
            else: ret[level].append(node.val)
            queue.append((node.left, level+1))
            queue.append((node.right, level+1))
        return ret