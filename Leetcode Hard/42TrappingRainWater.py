#https://leetcode.com/problems/trapping-rain-water/
class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        counter = 0
        minimum = min(height[left], height[right])
        while left < right:
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
            minimum = max(minimum, min(height[left], height[right]))
            if minimum - height[left] > 0:
                counter += minimum - height[left]
            if minimum - height[right] > 0:
                counter += minimum - height[right]
        return counter

#Brute Force is too Slow
class Solution:
    def trap(self, height: List[int]) -> int:
    #1. Cut out the zeros at the ends
    #2. Fill in the holes, and track how many times we do that
    #3. Reduce everything by 1
    #Repeat until list is of length < 3
        left, right = 0, (len(height)-1)
        counter = 0
        while right-left >= 2:
            while height[left] == 0 and left < right:
                left += 1
            while height[right] == 0 and left < right:
                right -= 1
            if left >= right or right-left < 2:
                break
            minimum = min(height[left], height[right])
            for i in range(left, right+1):
                if height[i] < minimum:
                    counter += minimum-height[i]
                    height[i] = minimum
            for i in range(left, right+1):
                height[i] -= 1
        return counter


    #Counter = 0,3,6
    #[0,1,0,2,1,0,1,3,2,1,2,1]
    #[1,0,2,1,0,1,3,2,1,2,1]
    #[1,1,2,1,1,1,3,2,2,2,1]
    #[0,0,1,0,0,0,2,1,1,1,0]
    #[1,0,0,0,2,1,1,1]
    #[1,1,1,1,2,1,1,1]
    #[0,0,0,0,1,0,0,0]
    #[1]
