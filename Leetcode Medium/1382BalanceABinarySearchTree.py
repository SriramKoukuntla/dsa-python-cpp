# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        arr = []
        def helper(root):
            if root == None: return
            helper(root.left)
            nonlocal arr
            arr.append(root.val)
            helper(root.right)
        helper(root)
        def helper2(arr):
            if len(arr) > 3:
                middleIdx = len(arr) // 2
                middle = TreeNode(arr[middleIdx])
                left = helper2(arr[0:middleIdx])
                right = helper2(arr[middleIdx+1:])
                middle.left = left
                middle.right = right
                return middle
            else:
                if len(arr) == 1: return TreeNode(arr[0])
                middle = TreeNode(arr[1])
                left = TreeNode(arr[0])
                middle.left = left
                if len(arr) == 2: return middle
                if len(arr) == 3:
                    right = TreeNode(arr[2])
                    middle.right = right
                    return middle
        return helper2(arr)