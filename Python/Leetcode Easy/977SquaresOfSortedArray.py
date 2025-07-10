class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # return sorted(list(map(lambda x: x*x, nums)))
        #This is O(log(N)) solution
        left, right = 0, len(nums)-1
        ret = []
        while left <= right:
            if abs(nums[left]) > abs(nums[right]):
                ret.append(nums[left]**2)
                left += 1
            else:
                ret.append(nums[right]**2)
                right -= 1
        return ret[::-1]
        #This is O(N) solution