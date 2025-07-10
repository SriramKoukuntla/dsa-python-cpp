#https://leetcode.com/problems/sliding-window-maximum/description/
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ret = []
        queue = deque([]) #(index, num)
        for i in range(len(nums)):
            node = (i, nums[i])
            while len(queue) != 0 and queue[-1][1] < node[1]:
                queue.pop()
            queue.append(node)            
            if i >= k-1:
                while queue[0][0] <= i-k:
                    queue.popleft()
                ret.append(queue[0][1])
        return ret