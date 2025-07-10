#https://leetcode.com/problems/counting-bits/
class Solution:
    def countBits(self, n: int) -> List[int]:
        tabArr = [0 for x in range(n+1)]
        for i in range(1, n+1):
            tabArr[i] = (i % 2) + tabArr[i//2]
        return tabArr

