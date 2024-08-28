#https://leetcode.com/problems/longest-repeating-character-replacement/description/
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        count, res, L, maxFreq = {}, 0, 0, 0
        for R in range(len(s)):
            count[s[R]] = count.get(s[R], 0) + 1
            maxFreq = max(maxFreq, count[s[R]])
            while (R-L+1)-maxFreq > k:
                count[s[L]] -= 1
                L += 1
            res = max(res, R-L+1)
        return res