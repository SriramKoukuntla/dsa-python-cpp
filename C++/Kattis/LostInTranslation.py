from collections import deque, defaultdict
n, m = map(int, input().split())
targetLangauges = set(input().split())
adjMat = defaultdict(list)
for i in range(m):
    l1, l2, c = input().split()
    adjMat[l1].append((l2, int(c)))
    adjMat[l2].append((l1, int(c)))
q = deque()
q.append(("English", 0))
visited = set()
targetLangaugesVisited = 0
ansCost = 0
while (len(q) != 0 and targetLangaugesVisited != len(targetLangauges)):
    tempVisited = set()
    addedCosts = {}
    N = len(q)
    for i in range(N):
        currLang, cost = q.popleft()
        if (currLang in visited): continue
        if (currLang in targetLangauges):
            if (currLang not in tempVisited): 
                targetLangaugesVisited += 1
                addedCosts[currLang] = cost
                ansCost += addedCosts[currLang]            
            elif (addedCosts[currLang] > cost):
                ansCost += (-addedCosts[currLang] + cost)
                addedCosts[currLang] = cost
                # print("targetLanguageAdded: " + currLang + " costAdded: " + str(cost))
        tempVisited.add(currLang)
        for childLang, childLangCost in adjMat[currLang]:
            q.append((childLang, childLangCost))
    visited.update(tempVisited)

if targetLangaugesVisited != len(targetLangauges): print("Impossible")
else: print(ansCost)