#https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dictionary = {}
        for word in strs:
            temp = [0 for __ in range(26)]
            for char in word:
                temp[ord(char) - ord("a")] += 1
            temp = tuple(temp)
            if temp in dictionary:
                dictionary[temp].append(word)
            else:
                dictionary[temp] = [word]
        ret = []
        for bitarray in dictionary:
            ret.append(dictionary[bitarray])
        return ret