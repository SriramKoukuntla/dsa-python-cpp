#start = 2:23
T = int(input())
for _ in range(T):
    b, k = map(int, input().split())
    oneLess = b-1
    res = 1

    for i in range(1, int(oneLess ** (1/2)) + 1):
        if oneLess % i != 0:
            continue
        greater = oneLess // i
        if (i <= k and i > res):
            res = i
        if (greater <= k and greater > res):
            res = greater

    print(res)