#https://leetcode.com/problems/valid-anagram/description/
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        dictionary1, dictionary2 = {}, {}
        for i in range(len(s)):
            dictionary1[s[i]] = 1 + dictionary1.get(s[i], 0) 
            dictionary2[t[i]] = 1 + dictionary2.get(t[i], 0) 
        if dictionary1 == dictionary2:
            return True
        return False