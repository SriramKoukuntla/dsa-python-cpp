#https://leetcode.com/problems/task-scheduler/description/
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