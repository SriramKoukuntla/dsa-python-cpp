#https://leetcode.com/problems/valid-parentheses/description/
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i in range(len(s)):
            if s[i] == "{" or s[i] == "(" or s[i] == "[":
                stack.append(s[i])
            else:
                if len(stack) == 0:
                    return False
                if s[i] == "}":
                    if stack.pop() != "{":
                        return False
                if s[i] == ")":
                    if stack.pop() != "(":
                        return False
                if s[i] == "]":
                    if stack.pop() != "[":
                        return False
        if len(stack) != 0:
            return False
        return True