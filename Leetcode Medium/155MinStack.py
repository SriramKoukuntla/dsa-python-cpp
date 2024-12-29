#https://leetcode.com/problems/min-stack/description/
class MinStack:

    def __init__(self):
        self.normal = []
        self.min = []

    def push(self, val: int) -> None:
        if len(self.normal) == 0:
            self.normal.append(val)
            self.min.append(val)
        else:
            self.normal.append(val)
            if val <= self.min[-1]:
                self.min.append(val) 
        
    def pop(self) -> None:
        val = self.normal.pop()
        if self.min[-1] == val:
            self.min.pop()
        return val

    def top(self) -> int:
        return self.normal[-1]

    def getMin(self) -> int:
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()