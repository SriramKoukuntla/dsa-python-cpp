#https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        current = root
        newNode = TreeNode(val)
        if root == None:
            return newNode
        while current:
            if val < current.val:
                if current.left != None:
                    current = current.left
                else:
                    current.left = newNode                    
                    break
            else:
                if current.right != None:
                    current = current.right 
                else:
                    current.right = newNode
                    break
        return root