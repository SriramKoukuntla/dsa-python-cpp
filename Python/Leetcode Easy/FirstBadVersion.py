#https://leetcode.com/problems/first-bad-version/description/
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 0, n
        while left <= right:
            middle = (left + right)/2
            if isBadVersion(middle):
                right = middle - 1
            else:
                left = middle + 1
        return left