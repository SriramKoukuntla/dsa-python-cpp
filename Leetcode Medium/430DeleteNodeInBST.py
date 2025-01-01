#https://leetcode.com/problems/delete-node-in-a-bst/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:        
        if root == None: return
        if key < root.val: root.left = self.deleteNode(root.left, key)
        elif key > root.val: root.right = self.deleteNode(root.right, key)
        else: 
            if root.left == None: return root.right
            elif root.right == None: return root.left
            
            curr = root.left
            while curr.right != None:
                curr = curr.right
            maxValue = curr.val
            root.val = maxValue
            root.left = self.deleteNode(root.left, maxValue)
        return root
    


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        arr = []
        def helper(node):
            if node == None: return
            helper(node.left)
            nonlocal arr
            arr.append(node.val)
            helper(node.right)
        helper(root)

        def helper2(arr):
            if len(arr) > 3:
                middleIdx = len(arr) // 2
                middle = TreeNode(arr[middleIdx])
                left = helper2(arr[0: middleIdx])
                right = helper2(arr[middleIdx+1: ])
                middle.left = left
                middle.right = right
                return middle
            else:
                if len(arr) == 0: return
                if len(arr) == 1: return TreeNode(arr[0])
                middle = TreeNode(arr[1])
                left = TreeNode(arr[0])
                middle.left = left
                if len(arr) == 2: return middle
                if len(arr) == 3: 
                    right = TreeNode(arr[2])
                    middle.right = right
                    return middle
        if key not in arr: return helper2(arr)
        arr.remove(key)
        return helper2(arr)