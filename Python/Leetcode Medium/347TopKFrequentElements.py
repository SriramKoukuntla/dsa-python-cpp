#https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        for num in nums:
            if num in dictionary: 
                dictionary[num] += 1
            else:
                dictionary[num] = 1
        bucketSort = [[] for __ in range(len(nums)+1)]
        for num in dictionary:
            bucketSort[dictionary[num]].append(num)
        ret = []
        for i, value in enumerate(bucketSort):
            for num in bucketSort[len(bucketSort)-1-i]:
                ret.append(num)
                if len(ret) == k:
                    return ret

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        for num in nums:
            if num in dictionary: 
                dictionary[num] += 1
            else:
                dictionary[num] = 1
        heap = []
        for num in dictionary:
            heapq.heappush(heap, (dictionary[num], num))
            if len(heap) > k:
                heapq.heappop(heap)
        ret = []
        for element in heap:
            ret.append(element[1])
        return ret
    

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        for num in nums:
            if num in dictionary: 
                dictionary[num] += 1
            else:
                dictionary[num] = 1
        heap = []
        for num in dictionary:
            heap.append((dictionary[num], num))
        heapq.heapify(heap)
        while len(heap) > k:
            heapq.heappop(heap)
        ret = []
        for element in heap:
            ret.append(element[1])
        return ret
    

