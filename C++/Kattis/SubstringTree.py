from functools import cache
N, L = input().split()
og = input()

@cache
def numSubstr(word):
    res = {}
    for length in range(1, len(word) + 1):
        tempSet = set()
        for start in range(len(word)-length + 1):
            substring = word[start:start + length-1]
            tempSet.add(substring)
        res.append(tempSet)

L1 = numSubstr(og)

prevL = L1
for i in range(L-1):
    nextL = []
