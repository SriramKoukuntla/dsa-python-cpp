#https://leetcode.com/problems/binary-tree-right-side-view/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        allList = []
        queue  = deque([(root, 0)])
        while len(queue) > 0:
            iterations = len(queue)
            for i in range(iterations):
                node, level = queue.popleft()
                if node == None: continue
                if len(allList) == level: allList.append([])
                allList[level].append(node.val)
                queue.append((node.left, level+1))
                queue.append((node.right, level+1))
        ret = [] 
        for List in allList:
            ret.append(List[-1])
        return ret