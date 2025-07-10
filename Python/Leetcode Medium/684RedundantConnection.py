#https://leetcode.com/problems/redundant-connection/
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        NumberOfNodes = len(edges)
        union = self.UnionFind(NumberOfNodes)
        for edge in edges:
            if not union.union(edge[0], edge[1]):
                return edge


    class UnionFind:
        def __init__(self, n):
            self.parr, self.rank = {}, {}
            for i in range(1, n + 1):
                self.parr[i] = i; self.rank[i] = 0
        
        def find(self, n):
            p = self.parr[n]
            while p != self.parr[p]:
                self.parr[p] = self.parr[self.parr[p]]
                p = self.parr[p]
            return p
        
        def union(self, n1, n2):
            p1, p2 = self.find(n1), self.find(n2)
            if p1 == p2:
                return False
            if self.rank[p1] > self.rank[p2]:
                self.parr[p2] = p1
            elif self.rank[p1] < self.rank[p2]:
                self.parr[p1] = p2
            else:
                self.parr[p1] = p2
                self.rank[p1] += 1
            return True