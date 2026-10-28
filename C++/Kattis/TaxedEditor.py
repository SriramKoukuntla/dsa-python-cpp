
from heapq import heappush, heappop

n, k = map(int, input().split())
books = [tuple(map(int, input().split())) for _ in range(n)]
books.sort(key=lambda x: x[1])

l, r = 1, sum(length for length, deadline in books)
ans = r

while l <= r:
    speed = (l + r) // 2

    maxHeap = []
    totalPages = 0
    count = 0

    for length, deadline in books:
        totalPages += length
        heappush(maxHeap, -length)

        if totalPages > speed * deadline:
            totalPages += heappop(maxHeap)
            count += 1

        if count > k:
            break

    if count <= k:
        ans = speed
        r = speed - 1
    else:
        l = speed + 1

print(ans)
