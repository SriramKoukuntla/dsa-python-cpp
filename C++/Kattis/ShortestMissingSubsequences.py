from bisect import bisect_right

v = input()
s = input()
n = int(input())

# Part 1: Find shortest missing subsequence length
seen = set()
complete = 0

for char in s:
    seen.add(char)

    if len(seen) == len(v):
        complete += 1
        seen.clear()

shortestLength = complete + 1

# Part 2: Preprocess character positions
positions = {char: [] for char in v}

for i, char in enumerate(s):
    positions[char].append(i)

# Part 3: Check whether a query is missing
def isMissing(q):
    prevIdx = -1

    for char in q:
        arr = positions[char]

        i = bisect_right(arr, prevIdx)

        if i == len(arr):
            return True

        prevIdx = arr[i]

    return False

# Part 4: Answer queries
for _ in range(n):
    q = input()

    if len(q) != shortestLength:
        print(0)
    elif isMissing(q):
        print(1)
    else:
        print(0)