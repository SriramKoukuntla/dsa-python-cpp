from math import factorial, comb
from functools import cache
import sys
sys.setrecursionlimit(5000)
@cache
def temp(m, h):
    if (h == -1):
        return 1
    if (h == 0):
        return 1

    once = [h-1, h-1]
    double = []
    for i in range(1, min(m, h) + 1):
        double.append((h - 1 - i, h - 1))

    ans = 0
    ans += temp(m, once[0]) * temp(m, once[1])
    for lr in double:
        tempAns = temp(m, lr[0]) * temp(m, lr[1])
        tempAns %= 1000000007
        tempAns *= 2
        tempAns %= 1000000007
        ans += tempAns
        ans %= 1000000007

    return ans


n = int(input())
for _ in range(n):
    m, h = map(int, input().split())
    m = min(m, h)
    ans = temp(m, h)
    print(ans)

    


