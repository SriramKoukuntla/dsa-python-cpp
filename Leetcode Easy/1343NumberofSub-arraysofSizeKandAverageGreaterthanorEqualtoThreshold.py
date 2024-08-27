#https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        L = 0
        total = 0
        counter = 0
        for R in range(len(arr)):
            if R - L + 1 > k:
                total -= arr[L]
                L += 1
            total += arr[R]
            if total//k >= threshold and R-L+1 == k:
                counter += 1
        return counter