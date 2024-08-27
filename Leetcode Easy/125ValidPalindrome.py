#https://leetcode.com/problems/valid-palindrome/description/
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        front, back = 0, len(s)-1
        while front < back:
            while front < back and not self.alphanum(s[front]):
                front += 1
            while front < back and not self.alphanum(s[back]):
                back -= 1
            if s[front].lower() != s[back].lower():
                return False
            front += 1
            back -= 1
        return True
            
    def alphanum(self, character):
        return (ord('a') <= ord(character) <= ord('z')
        or ord('A') <= ord(character) <= ord('Z')
        or ord('0') <= ord(character) <= ord('9'))