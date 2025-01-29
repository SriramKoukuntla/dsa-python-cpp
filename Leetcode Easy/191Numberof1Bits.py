#https://leetcode.com/problems/number-of-1-bits/submissions/1524771991/
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            count += (n%2)
            n >>= 1
        return count

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            count += (n%2)
            n //= 2
        return count