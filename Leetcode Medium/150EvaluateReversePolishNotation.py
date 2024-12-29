#https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1491625252/
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for char in tokens:
            if char in "+-/*":
                r = stack.pop()
                l = stack.pop()
                if char == "*":
                    stack.append(l * r)
                elif char == "/":
                    stack.append(int(float(l) / r))
                elif char == "+":
                    stack.append(l + r)
                else:
                    stack.append(l - r)
            else:
                stack.append(int(char))
        return stack.pop()