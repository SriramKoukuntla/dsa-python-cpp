#find triangles
from collections import defaultdict, deque
import sys
N, M = map(int, input().split()) #num dots, num lines
points = []
lines = []
adjMatrix = defaultdict(list)
for i in range(N):
    x, y = tuple(map(int, input().split()))
    points.append((x, y))
for i in range(M):
    pointI, pointJ = map(int, input().split())
    lines.append((pointI, pointJ))
    adjMatrix[points[pointI]].append(points[pointJ])
    adjMatrix[points[pointJ]].append(points[pointI])

queue = deque([points[0]])
visited = set()
while (len(queue) != 0):
    currPoint = queue.popleft()
    if currPoint in visited:
        continue
    visited.add(currPoint)
    for nextPoint in adjMatrix[currPoint]:
        queue.append(nextPoint)

if len(visited) != N:
    print(-1)
    sys.exit()

def pointCheck(pointA, pointB, pointC): #check if pointC is on line AB
    # print(str(type(pointA)) + ", " + str(type(pointB)) + ", " + str(type(pointC)))
    vectorAB = (pointB[0]-pointA[0], pointB[1]-pointA[1])
    vectorAC = (pointC[0]-pointA[0], pointC[1]-pointA[1])
    crossProduct = (vectorAB[0] * vectorAC[1]) - (vectorAB[1] * vectorAC[0])
    if (crossProduct != 0):
        return False
    if (not (min(pointA[0], pointB[0]) <= pointC[0] <= max(pointA[0], pointB[0]))):
        return False
    if (not (min(pointA[1], pointB[1]) <= pointC[1] <= max(pointA[1], pointB[1]))):
        return False
    return True

def cross(a, b, p):
    # Cross product of vectors AB and AP
    return (
        (b[0] - a[0]) * (p[1] - a[1])
        - (b[1] - a[1]) * (p[0] - a[0])
    )

def intersects(a, b, c, d):
    c1 = cross(a, b, c)
    c2 = cross(a, b, d)
    c3 = cross(c, d, a)
    c4 = cross(c, d, b)
    return c1 * c2 < 0 and c3 * c4 < 0

for i in range(len(points)):
    pointC = points[i]
    for line in lines:
        if i == line[0] or i == line[1]:
            continue
        pointA = points[line[0]]
        pointB = points[line[1]]
        if pointCheck(pointA, pointB, pointC):
            print(-1)
            sys.exit()

for i in range(len(lines)):
    for j in range(i+1, len(lines)):
        line1 = lines[i]
        line2 = lines[j]
        if intersects(points[line1[0]], points[line1[1]], points[line2[0]], points[line2[1]]):
            print(-1)
            sys.exit()



