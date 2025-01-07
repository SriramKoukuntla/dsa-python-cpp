#https://leetcode.com/problems/last-stone-weight/description/
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [] #This is a min heap, but is actually max heap because we mulitply by -1
        for stone in stones: 
            heapq.heappush(heap, -1 * stone)
        while len(heap) > 1:
            stone1 = -1 * heapq.heappop(heap) #max
            stone2 = -1 * heapq.heappop(heap) #min
            if stone1 != stone2:
                heapq.heappush(heap, -1*(stone1-stone2))
        if len(heap) == 0: return 0
        else: return -1 * heap[0]