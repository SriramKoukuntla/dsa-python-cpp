#https://leetcode.com/problems/kth-largest-element-in-an-array/description/
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for value in nums: heapq.heappush(heap, value)
        for i in range(len(nums)-k): heapq.heappop(heap)
        return heapq.heappop(heap)