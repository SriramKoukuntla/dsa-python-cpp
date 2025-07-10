#https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return heapq.nsmallest(k, points, key = lambda point: pow(point[0], 2) + pow(point[1], 2))

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for point in points: heap.append([pow(point[0], 2) +  pow(point[1], 2), point])
        return [item[1] for item in heapq.nsmallest(k, heap, key = lambda item: item[0])]

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for point in points:
            distance = pow(point[0], 2) + pow(point[1], 2)
            heapq.heappush(heap, [distance, point])
        newList = []
        for i in range(k):
            newList.append(heapq.heappop(heap)[1])
        return newList