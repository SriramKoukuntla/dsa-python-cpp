#https://leetcode.com/problems/implement-stack-using-queues/description/
class MyStack:
    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def push(self, x: int) -> None:
        if len(self.queue1) == 0:
            self.queue1.append(x)
            for item in self.queue2:
                self.queue1.append(item)
            self.queue2 = []
        else:
            self.queue2.append(x)
            for item in self.queue1:
                self.queue2.append(item)
            self.queue1 = []

    def pop(self) -> int:
        if len(self.queue1) == 0:
            return self.queue2.pop(0)
        else:
            return self.queue1.pop(0)

    def top(self) -> int:
        if len(self.queue1) == 0:
            return self.queue2[0]
        else:
            return self.queue1[0]
        

    def empty(self) -> bool:
        return len(self.queue1) == 0 and len(self.queue2) == 0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()