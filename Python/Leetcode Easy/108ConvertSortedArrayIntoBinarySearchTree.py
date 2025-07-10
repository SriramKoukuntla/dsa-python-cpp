#https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#1, 2, 3, 4, 5, 6, 7,

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(arr):
            if len(arr) > 3:
                middleIdx = len(arr) // 2
                middle = TreeNode(arr[middleIdx])
                left = helper(arr[0:middleIdx])
                right = helper(arr[middleIdx+1:])
                middle.left = left
                middle.right = right
                return middle
            else:
                if len(arr) == 3:
                    middle = TreeNode(arr[1])
                    left = TreeNode(arr[0])
                    right = TreeNode(arr[2])
                    middle.left = left
                    middle.right = right
                    return middle
                elif len(arr) == 2:
                    middle = TreeNode(arr[1])
                    left = TreeNode(arr[0])
                    middle.left = left
                    return middle
                elif len(arr) == 1:
                    middle = TreeNode(arr[0])
                    return middle
        root = helper(nums)
        return root 