#https://leetcode.com/problems/valid-parentheses/description/
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        idx = 0
        while idx < len(s):
            curr = s[idx]
            if curr == "(" or curr == "{" or curr == "[":
                stack.append(curr)
            elif len(stack) == 0:
                return False
            elif curr == ")" and stack.pop() != "(":
                return False
            elif curr == "}" and stack.pop() != "{":
                return False
            elif curr == "]" and stack.pop() != "[":
                return False
            idx += 1
        return len(stack) == 0