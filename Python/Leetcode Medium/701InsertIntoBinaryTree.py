#https://leetcode.com/problems/insert-into-a-binary-search-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#Better Solution
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root == None: return TreeNode(val)
        parent = None
        curr = root
        while curr != None:
            parent = curr
            if val < curr.val: curr = curr.left
            else: curr = curr.right
        if val < parent.val: parent.left = TreeNode(val)
        else: parent.right = TreeNode(val)
        return root

class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        directions = deque([])
        curr = root
        while curr != None:
            if val < curr.val:
                curr = curr.left
                directions.append("left")
            else: 
                curr = curr.right
                directions.append("right")
        curr = root
        while len(directions) > 1:
            direction = directions.popleft()
            if direction == "left": curr = curr.left
            else: curr = curr.right
        if curr == None: return TreeNode(val)
        if directions.popleft() == "left": curr.left = TreeNode(val)
        else: curr.right = TreeNode(val)
        return root