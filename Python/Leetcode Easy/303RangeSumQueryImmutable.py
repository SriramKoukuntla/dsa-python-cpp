#https://leetcode.com/problems/range-sum-query-immutable/description/
class NumArray:
    def __init__(self, nums: List[int]):
        self.tabArr = [0 for i in range(len(nums)+1)]
        for i in range(1, len(nums)+1):
            self.tabArr[i] = self.tabArr[i-1] + nums[i-1]

    def sumRange(self, left: int, right: int) -> int:
        return self.tabArr[right+1]-self.tabArr[left]