#https://leetcode.com/problems/min-stack/
class MinStack(object):

    def __init__(self):
        self.stack = []
        self.stackMin = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        if len(self.stackMin) == 0:
            self.stackMin.append(val)
        else:
            if self.stackMin[-1] < val:
                self.stackMin.append(self.stackMin[-1])
            else:
                self.stackMin.append(val)
        

    def pop(self):
        """
        :rtype: None
        """
        self.stackMin.pop()
        return self.stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.stackMin[-1]