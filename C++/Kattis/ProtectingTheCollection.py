#solution. Trace path from lazer exiting the wall and entering the wall, and then place a mirror on the interception

n, laserCol, sensorRow = map(int, input().split())
grid = [input().split() for _ in range(n)]

# Directions: North, East, South, West
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

# Reflection direction mappings
slash = [1, 0, 3, 2]      # /
backslash = [3, 2, 1, 0]  # \

def trace(r, c, d):
    visited = set()
    empty = set()

    while 0 <= r < n and 0 <= c < n:
        if (r, c, d) in visited:
            break

        visited.add((r, c, d))

        if grid[r][c] == '.':
            empty.add((r, c))
        elif grid[r][c] == '/':
            d = slash[d]
        else:
            d = backslash[d]

        r += dr[d]
        c += dc[d]

    return empty, (r, c, d)


# Trace from laser: starts north of the grid, going south
laserCells, laserExit = trace(0, laserCol - 1, 2)

# Check if laser already reaches sensor
if laserExit == (sensorRow - 1, n, 1):
    print("YES")
else:
    # Trace backward from sensor, going west
    sensorCells, _ = trace(sensorRow - 1, n - 1, 3)

    # Can we connect the two paths with one mirror?
    if laserCells & sensorCells:
        print("YES")
    else:
        print("NO")
