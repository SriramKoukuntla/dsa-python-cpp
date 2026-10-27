import sys

lines = [list(map(int, input().split())) for _ in range(3)]
pegs = [line[1:] for line in lines]

n = sum(len(peg) for peg in pegs)
positions = [-1] * (n + 1)

for i, peg in enumerate(pegs):
    for j, disk in enumerate(peg):
        if disk < 1 or disk > n or positions[disk] != -1:
            print("No")
            sys.exit()

        positions[disk] = i

        if j > 0 and peg[j - 1] < disk:
            print("No")
            sys.exit()

def solve(n, start, goal, spare):
    if n == 0:
        return 0

    if positions[n] == start:
        return solve(n - 1, start, spare, goal)

    if positions[n] == goal:
        result = solve(n - 1, spare, goal, start)
        if result == -1:
            return -1
        return (1 << (n - 1)) + result

    return -1

elapsed = solve(n, 0, 2, 1)

if elapsed == -1:
    print("No")
else:
    print((1 << n) - 1 - elapsed)