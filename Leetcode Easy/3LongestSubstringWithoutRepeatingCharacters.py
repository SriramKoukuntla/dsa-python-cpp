#https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        window = set()
        L, Length = 0, float("-inf")

        for R in range(len(s)):
            while s[R] in window:
                window.remove(s[L])
                L += 1
            Length = max(Length, R-L+1)
            window.add(s[R])
        return 0 if Length == float("-inf") else Length