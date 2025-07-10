#https://leetcode.com/problems/minimum-window-substring/
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        #Sliding window technique
        #Move right until window has every element
        #ADABECODEBANC
        #ADABEC
        #ABEC
        #BEC
        #BECODEBA
        #CODEBA
        #BANC   
        def hash(char):
            if char.islower(): return ord(char)-ord("a")
            else: return ord(char)-ord("A") + 26
        window = [0 for __ in range(52)]
        needed = [0 for __ in range(52)]
        tset = set() #This will contain every character contained in t
        for char in t:
            needed[hash(char)] += 1
            tset.add(char)
        def reduce():
            for char in tset:
                if window[hash(char)] < needed[hash(char)]: return False
            return True

        smallestSubstring = s + "hello"
        left = 0
        for right in range(len(s)):
            window[hash(s[right])] += 1
            while reduce():
                newSubstring = s[left:right+1]
                if len(newSubstring) < len(smallestSubstring): smallestSubstring = newSubstring                
                window[hash(s[left])] -= 1
                left += 1
                while left < len(s) and s[left] not in tset:
                    window[hash(s[left])] -= 1
                    left += 1
        if smallestSubstring == s + "hello": return ""
        return smallestSubstring