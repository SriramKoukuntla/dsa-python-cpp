import sys

r, m = map(int, input().split())

if r == m:
    print(1)
    sys.exit()

seen = bytearray(m + 1)
#4, 5, 6....
#a_x = a_x-1 + d
#2, 3, 7

#1, 3
#1, 3, 7, 12, 15, 
14, 12, 8, 3 

if r <= m:
    seen[r] = True

prevAs = [r]
idx = 1

while True:
    while seen[idx]:
        idx += 1

    nextA = prevAs[-1] + idx

    for previous in prevAs:
        difference = nextA - previous
        if difference <= m:
            seen[difference] = 1

    if nextA <= m:
        seen[nextA] = 1

    prevAs.append(nextA)

    if seen[m]:
        print(len(prevAs))
        break