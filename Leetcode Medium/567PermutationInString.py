#https://leetcode.com/problems/permutation-in-string/
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        needed = [0 for __ in range(26)]
        window = [0 for __ in range(26)]
        for char in s1:
            needed[ord(char)-ord("a")] += 1
        left = 0
        for right in range(len(s2)):
            window[ord(s2[right])-ord("a")] += 1
            while window[ord(s2[right])-ord("a")] > needed[ord(s2[right])-ord("a")]:
                window[ord(s2[left])-ord("a")] -= 1
                left += 1
            if right - left + 1 == len(s1):
                return True
        return False

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        needed = [0 for __ in range(26)]
        window = [0 for __ in range(26)]
        for char in s1:
            needed[ord(char)-ord("a")] += 1
        left = 0
        for right in range(len(s2)):
            window[ord(s2[right])-ord("a")] += 1
            if right - left + 1 > len(s1):
                window[ord(s2[left])-ord("a")] -= 1
                left += 1
            if window == needed:
                return True
        return False