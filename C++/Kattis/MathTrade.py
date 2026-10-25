def get(hasWant):
    for has in hasWant:
        return has
    
n = int(input())
hasWant = {}
for i in range(n):
    person, has, want= input().split()
    hasWant[has] = want
biggestChain = 0

while len(hasWant) != 0:
    start = get(hasWant)
    curr = hasWant[start]
    currCycle = set([start, curr])
    while (start != curr and curr in hasWant):
        curr = hasWant[curr]
        currCycle.add(curr)
    for has in currCycle:
        if has in hasWant: hasWant.pop(has)

    if start == curr: 
        if (len(currCycle) > biggestChain): biggestChain = len(currCycle)

if (biggestChain == 0): print("No trades possible")
else: print(biggestChain)