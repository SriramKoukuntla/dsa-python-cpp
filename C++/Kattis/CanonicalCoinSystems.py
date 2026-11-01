from functools import cache
import sys
sys.setrecursionlimit(10000)
n = int(input())
denominations = list(map(int, input().split()))
denominations.sort()
denominations = denominations[::-1]

@cache
def counting(val): #returns min num of coins to get to val
    global denominations
    if (val in denominations): 
        return 1
    res = float("inf")
    for denomination in denominations:
        nextVal = val-denomination
        if nextVal < 0: 
            continue
        tempAns = counting(nextVal)
        if res != float("inf") and tempAns < res:
            print("non-canonical")
            sys.exit()
        res = min(res, tempAns)
    
    return res + 1

for i in range(1, denominations[0] * 2):
    counting(i)
print("canonical")
