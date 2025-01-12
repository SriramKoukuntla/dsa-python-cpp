#https://neetcode.io/problems/string-encode-and-decode
class Solution:

    def encode(self, strs: List[str]) -> str:
        ret = ""
        for string in strs:
            start = str(len(string)) + "#"
            start += string
            ret += start
        return ret

    "2#we3#say1#:3#yes"
    def decode(self, s: str) -> List[str]:
        ret = []
        length = ""
        i = 0
        while i < len(s):
            char = s[i]
            if char.isnumeric():
                length += char
                i += 1
            else: #char is == #
                templength = int(length)
                ret.append(s[i+1:i+1+int(length)])
                i += (int(length))+1     
                length = ""
        return ret