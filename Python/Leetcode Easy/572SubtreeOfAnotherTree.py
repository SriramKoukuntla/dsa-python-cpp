#https://leetcode.com/problems/subtree-of-another-tree/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def same(node):
            stack1 = [node]
            stack2 = [subRoot]
            while len(stack1) > 0 and len(stack2) > 0:
                node1 = stack1.pop()
                node2 = stack2.pop()
                if node1 == None and node2 == None: continue
                if node1 == None or node2 == None: return False
                if node1.val != node2.val: return False
                stack1.append(node1.left)
                stack1.append(node1.right)
                stack2.append(node2.left)
                stack2.append(node2.right)
            if len(stack1) > 0 or len(stack2) > 0: return False
            return True
        
        ret = False
        def helper(node):
            if node == None: return
            if node.val == subRoot.val: 
                if same(node): 
                    nonlocal ret
                    ret = True
            helper(node.left)
            helper(node.right)

        helper(root)
        return ret