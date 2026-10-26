#start 11:41
from heapq import *
from collections import deque
import sys
c = int(input())
votes = list(map(int, input().split()))

first, second = -1, -1
firstIdx, secondIdx = -1, -1
sum = 0
for i, vote in enumerate(votes):
    sum += vote
    if (vote > first): 
        secondIdx = firstIdx
        second = first
        firstIdx = i
        first = vote
    elif (vote > second): 
        second = vote
        secondIdx = i
toWin = sum // 2 + 1

count = 0
while (True):
    smallest = float("inf")
    for i, vote in enumerate(votes):
        if (vote == -1): continue
        smallest = min(smallest, vote)
        if (vote >= toWin):
            if (i == secondIdx): print(count)
            else: print("IMPOSSIBLE TO WIN")
            sys.exit()
    if (smallest == float("inf")):
        print("IMPOSSIBLE TO WIN")
        sys.exit()

    toAdd = 0
    for i, vote in enumerate(votes):
        if (vote == smallest): 
            if (i == secondIdx):
                print("IMPOSSIBLE TO WIN")
                sys.exit()
            toAdd += vote
            votes[i] = -1
            continue
    votes[secondIdx] += toAdd
    count += 1
