#https://leetcode.com/problems/product-of-array-except-self/description/
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #1, 2, 3, 4
        #1, 1, 2, 6
        #24, 12, 4, 1
        
        ret = [1 for __ in range(len(nums))]
        tempLeft = 1
        for i in range(len(nums)-1):
            tempLeft *= nums[i]
            ret[i+1] *= tempLeft
        tempRight = 1
        for i in range(len(nums)-1):
            tempRight *= nums[len(nums)-1-i]
            ret[len(nums)-2-i] *= tempRight
        return ret
    
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #1, 2, 3, 4
        #1, 2, 6, 24
        #24, 24, 12, 4
        left = []
        right = deque([])
        tempLeft = 1
        for num in nums:
            tempLeft *= num
            left.append(tempLeft)
        tempRight = 1
        for i in range(len(nums)):
            tempRight *= nums[len(nums)-1-i]
            right.appendleft(tempRight)
        right = list(right)
        ret = []
        for i in range(len(nums)):
            if i == 0:
                ret.append(right[1])
                continue
            if i == len(nums)-1:
                ret.append(left[len(nums)-2])
                continue
            ret.append(left[i-1] * right[i+1])
        return ret
