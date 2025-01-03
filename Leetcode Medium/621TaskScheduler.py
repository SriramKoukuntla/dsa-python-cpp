#https://leetcode.com/problems/task-scheduler/description/
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dictionary = {}
        for task in tasks: 
            if task in dictionary: dictionary[task] += 1
            else: dictionary[task] = 1
        heap = [] #Number of tasks still there, Interval Waiting
        waitingQueue = deque([])
        for task in dictionary: heapq.heappush(heap, [-1 * dictionary[task], 0]) 
        clock = 0
        while len(heap) > 0 or len(waitingQueue) > 0:
            while len(waitingQueue) > 0 and waitingQueue[0][1] <= clock: heapq.heappush(heap, waitingQueue.popleft())
            if len(heap) == 0:
                clock += 1
                continue
            task = heapq.heappop(heap)
            if task[1] <= clock:
                count = task[0] + 1
                if count != 0: waitingQueue.append([count, clock+n+1])
            clock += 1
        return clock
    
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dictionary = {}
        for task in tasks:
            if task in dictionary: dictionary[task] += 1
            else: dictionary[task] = 1
        heap = []
        for task in dictionary: heapq.heappush(heap, [0, task, dictionary[task]])
        clock = 0
        while len(heap) > 0:
            value = heapq.heappop(heap)
            if value[0] <= clock:
                num = value[2] - 1
                if num != 0: heapq.heappush(heap, [value[0]+n+1, task, num])
            else:
                heapq.heappush(heap, value)
            clock += 1
        return clock