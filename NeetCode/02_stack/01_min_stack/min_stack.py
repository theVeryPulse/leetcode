class MinStack:
    data = []
    def __init__(self):
        self.data.clear()

    def push(self, val: int) -> None:
        if len(self.data) == 0:
            self.data.append((val, val))
        else:
            if val <= self.data[-1][1]:
                self.data.append((val, val))
            else:
                self.data.append((val, self.data[-1][1]))

    def pop(self) -> None:
        self.data.pop()        

    def top(self) -> int:
        if len(self.data) != 0:
            return self.data[-1][0]
        else:
            return 0

    def getMin(self) -> int:
        if len(self.data) != 0:
            return self.data[-1][1]
        else:
            return 0

        


# Your MinStack object will be instantiated and called as such:
val = -1
obj = MinStack()
obj.push(val)
param_3 = obj.top()
param_4 = obj.getMin()
obj.pop()