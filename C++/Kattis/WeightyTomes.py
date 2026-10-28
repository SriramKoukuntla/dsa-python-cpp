from functools import cache
import sys
sys.setrecursionlimit(100000)

n, m = map(int, input().split())

if m == 1:
    print(n, 1)
    sys.exit()

if n == 0:
    print(0, 0)
    sys.exit()

@cache
def dp(diff, k):
    if diff == 0:
        return 0
    if k == 1:
        return diff

    ret = float("inf")

    for i in range(1, diff + 1):
        # Pallet breaks: limit is in [0, i-1]
        doesBreak = dp(i - 1, k - 1)

        # Pallet survives: limit is in [i, diff]
        doesNotBreak = dp(diff - i, k)

        numExperiments = 1 + max(doesBreak, doesNotBreak)
        ret = min(ret, numExperiments)

    return ret


# Minimum worst-case experiments
temp = dp(n, m)

# Find ALL optimal first experiments
ans = []

for i in range(1, n + 1):
    doesBreak = dp(i - 1, m - 1)
    doesNotBreak = dp(n - i, m)

    numExperiments = 1 + max(doesBreak, doesNotBreak)

    if numExperiments == temp:
        ans.append(i)

minVal = min(ans)
maxVal = max(ans)

if minVal == maxVal:
    print(temp, minVal)
else:
    print(temp, f"{minVal}-{maxVal}")