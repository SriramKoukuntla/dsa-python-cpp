#https://leetcode.com/problems/longest-mountain-in-array/description/
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        counter = 0
        i = 1 #Start at 1, end at len(arr)
        while (i < len(arr)):
            tempCounter = 1
            ascend, descend = False, False
            while (i < len(arr) and arr[i-1] < arr[i]):
                tempCounter += 1
                ascend = True
                i += 1
            while (i < len(arr) and arr[i-1] > arr[i]):
                tempCounter += 1
                descend = True
                i += 1
            while (i < len(arr) and arr[i-1] == arr[i]):
                i += 1
            if (ascend and descend):
                counter = max(counter, tempCounter)
        return counter