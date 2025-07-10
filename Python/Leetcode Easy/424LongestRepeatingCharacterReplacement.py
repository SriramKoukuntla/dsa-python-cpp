#https://leetcode.com/problems/longest-repeating-character-replacement/description/
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        count, res, L, maxFreq = {}, 0, 0, 0
        for R in range(len(s)):
            count[s[R]] = count.get(s[R], 0) + 1
            maxFreq = max(maxFreq, count[s[R]])
            while (R-L+1)-maxFreq > k:
                count[s[L]] -= 1
                L += 1
            res = max(res, R-L+1)
        return res
    
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        countArray = [0 for __ in range(26)]
        bucketArray = [set() for __ in range(len(s)+1)]
        for char in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            bucketArray[0].add(char)
        left = 0
        currSize, retSize = 0, 0
        maxCharCount = 0
        for right in range(len(s)):
            currSize += 1
            countArray[ord(s[right])-ord("A")] += 1
            bucketArray[countArray[ord(s[right])-ord("A")]].add(s[right])
            bucketArray[countArray[ord(s[right])-ord("A")]-1].remove(s[right])
            maxCharCount = max(maxCharCount, countArray[ord(s[right])-ord("A")])
            while currSize-maxCharCount > k:
                currSize -= 1
                countArray[ord(s[left])-ord("A")] -= 1
                bucketArray[countArray[ord(s[left])-ord("A")]].add(s[left])
                bucketArray[countArray[ord(s[left])-ord("A")]+1].remove(s[left])
                if len(bucketArray[maxCharCount]) == 0:
                    maxCharCount -= 1
                left += 1
            retSize = max(retSize, currSize)
        return retSize

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        countArray = [0 for __ in range(26)]
        left = 0
        currSize, retSize = 0, 0
        for right in range(len(s)):
            currSize += 1
            countArray[ord(s[right])-ord("A")] += 1
            maxCharCount = 0
            for count in countArray:
                maxCharCount = max(maxCharCount, count)
            if currSize-maxCharCount > k:
                currSize -= 1
                countArray[ord(s[left])-ord("A")] -= 1
                maxCharCount = 0
                for count in countArray:
                    maxCharCount = max(maxCharCount, count)
                left += 1
            retSize = max(retSize, currSize)
        return retSize