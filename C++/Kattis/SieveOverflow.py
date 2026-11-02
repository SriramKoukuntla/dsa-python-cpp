#Start, 6:10
from math import *
from functools import cache

m = int(input())
isPrime = ["NONE"] * (floor(pow(m, 0.5))+1)
upperBounds = floor(sqrt(len(isPrime)-1))
for i in range(2, upperBounds+1):
    if isPrime[i] == "NONE":
        isPrime[i] = "PRIME"
        multiple = i * 2
        while multiple <= len(isPrime)-1:
            isPrime[multiple] = "COMPOSITE"
            multiple += i
for i in range(upperBounds+1, len(isPrime)):
    if isPrime[i] == "NONE":
        isPrime[i] = "PRIME"
    
l = 2
r = m
ans = -1
while (l <= r):
    Failed = False
    n = l + (r-l)//2
    # print("l: " + str(l) + " r: " + str(r) + " n:" + str(n))

    limit = floor(pow(n, 0.5))
    for i in range(2, limit+1):
        if (isPrime[i] != "PRIME"):
            continue

        # print("special: " + str((n - (n % i)) + i))
        if ((n - (n % i)) + i) > m:
            r = n-1
            Failed = True
            break
    if Failed:
        continue
    l = n+1
    ans = max(ans, n)
print(ans)