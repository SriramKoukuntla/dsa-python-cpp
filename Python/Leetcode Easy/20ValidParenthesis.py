#https://leetcode.com/problems/valid-parentheses/description/
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        convert = {"}":"{",     ")":"(",    "]": "["}
        for char in s:
            if char in convert:
                if len(stack) == 0:
                    return False
                if stack.pop() != convert[char]:
                    return False
            else:
                stack.append(char)
        return len(stack) == 0