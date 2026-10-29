import sys
from heapq import *
from collections import *
s, n = map(int, input().split())
toilet = [] #maxHeap
everyPerson = [] #holds deadlines minHeap
for i in range(n):
    deadline, needs = input().split()
    deadline = int(deadline)
    if (needs == "y"): toilet.append(-1 * deadline)
    else: everyPerson.append(deadline)
heapify(toilet)
heapify(everyPerson)


toiletPaperScheduling = defaultdict(int)
prevIdx = float("inf")
while (len(toilet) != 0):
    currDeadline = -1 * heappop(toilet)
    scheduleIdx = currDeadline-1
    if (scheduleIdx >= prevIdx):
        scheduleIdx = prevIdx-1
    if (scheduleIdx < 0):
        print("No")
        sys.exit()
    prevIdx = scheduleIdx
    toiletPaperScheduling[scheduleIdx] = 1


time = 0
while (len(everyPerson) != 0):
    a = len(everyPerson)
    b = s
    if (time in toiletPaperScheduling): b -= toiletPaperScheduling[time]
    canTake = min(a, b)
    for i in range(canTake): 
        temp = heappop(everyPerson)
        if (temp <= time):
            print("No")
            sys.exit()
    time+=1
print("Yes")

