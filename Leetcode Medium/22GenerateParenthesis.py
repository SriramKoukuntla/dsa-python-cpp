#https://leetcode.com/problems/generate-parentheses/
#Back tracking solution
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        stack = []
        def helper(openC, closedC):
            nonlocal ret, stack
            if openC == closedC == n:
                ret.append("".join(stack))
                return
            if openC < n:
                stack.append("(")
                helper(openC+1, closedC)
                stack.pop()
            if closedC < openC:
                stack.append(")")
                helper(openC, closedC+1)
                stack.pop()
        helper(0, 0)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        def helper(openC, closedC, string):
            nonlocal ret
            if openC == n:
                for i in range(n-closedC):
                    string += ")"
                ret.append(string)
            elif openC == closedC:
                string += "("
                helper(openC+1, closedC, string)
            else:
                temp1 = string
                temp1 += "("
                helper(openC+1, closedC, temp1)
                temp2 = string
                temp2 += ")"
                helper(openC, closedC+1, temp2)
        helper(0, 0, "")
        return ret