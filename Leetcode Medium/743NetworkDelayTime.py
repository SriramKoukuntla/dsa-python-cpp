#https://leetcode.com/problems/network-delay-time/description/

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjMat = defaultdict(list)
        for start, end, distance in times:
            adjMat[start].append((end, distance))

        ret = float('-inf')
        seen = set()
        priorityQueue = [(0, k)]
        while priorityQueue:
            dist, node = heapq.heappop(priorityQueue)
            print((dist, node))
            if node in seen: continue
            ret = max(ret, dist)
            seen.add(node)
            for destination, distance in adjMat[node]:
                heapq.heappush(priorityQueue, (distance + dist, destination))
        
        return -1 if n != len(seen) else ret