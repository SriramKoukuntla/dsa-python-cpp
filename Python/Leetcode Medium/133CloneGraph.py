#https://leetcode.com/problems/clone-graph/description/
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited = {}
        def helper(node):
            if node == None: return
            if node in visited: return visited[node]
            copy = Node(node.val)
            visited[node] = copy
            for neighbor in node.neighbors:
                copy.neighbors.append(helper(neighbor))
            return copy
        return helper(node)