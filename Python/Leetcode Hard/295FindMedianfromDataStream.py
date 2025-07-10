#Two categories of data. Smaller values, Larger Values. Smaller values will be stored in max heap, bigger values will be stored in min heap.
#If we want the median, we view the top value of the heap that is larger. If they are of equal size then we look at the top values for both heaps and average the value. 
#If we want to add a new value, then we we look if the smaller value heaps (max heap is larger)
#We always want the max heap for the smaller values to be equal to or larger thant he min heap for the larger values in size.
import heapq
class MedianFinder:

    def __init__(self):
        self.bigH = [] 
        self.smallH = [] #This will have negative numbers

    def addNum(self, num: int) -> None:
        temp = []
        if len(self.smallH) > len(self.bigH):
            temp.append(-1 * heapq.heappop(self.smallH))
            temp.append(num)
        else:
            if len(self.smallH) != 0:
                temp.append(-1 * heapq.heappop(self.smallH))
                temp.append(heapq.heappop(self.bigH))
            temp.append(num)
        temp.sort()
        if len(temp) == 1:
            heapq.heappush(self.smallH, (-1 * temp[0]))
        elif len(temp) == 2:
            heapq.heappush(self.smallH, (-1 * temp[0]))
            heapq.heappush(self.bigH, temp[1])
        elif len(temp) == 3:
            heapq.heappush(self.smallH, (-1 * temp[0]))
            heapq.heappush(self.smallH, (-1 * temp[1]))
            heapq.heappush(self.bigH, temp[2])

    def findMedian(self) -> float:
        if len(self.bigH) == len(self.smallH):
            return (self.bigH[0] + (-1 * self.smallH[0])) / 2
        else:
            return (-1 * self.smallH[0])        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()