from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
n = int(input())
adjMat = defaultdict(list)
for i in range(n):
    a, b = map(int, input().split())
    adjMat[a].append(b)
    adjMat[b].append(a)

subsetSizes = {}
visited = set()
def dfs(node, visited, adjMat, subsetSizes): 
    if (node in visited): return 0
    visited.add(node)
    ans = 1
    for child in adjMat[node]:
        ans += dfs(child, visited, adjMat, subsetSizes)
    subsetSizes[node] = ans
    return ans

dfs(0, visited, adjMat, subsetSizes)


N = n + 1
bestPairsRemoved = -1
damageControl = 0

def pairsRemoved(components):
    sum = 0
    sumSq = 0
    for component in components:
        sum += component
        sumSq += (component * component)
    return (pow(sum, 2) - sumSq)//2

for node in range(N):
    components = []
    currSize = subsetSizes[node]
    for child in adjMat[node]:
        if (subsetSizes[child] < currSize): components.append(subsetSizes[child])
        else: components.append(N - subsetSizes[node])

    pairsRem = pairsRemoved(components)
    if (pairsRem > bestPairsRemoved):
        bestPairsRemoved = pairsRem
        big1 = 0
        big2 = 0
        if (len(components) > 1):
            for component in components:
                if (component > big1):
                    big2 = big1
                    big1 = component
                elif (component > big2):
                    big2 = component
        damageControl = big1 * big2
print(bestPairsRemoved, bestPairsRemoved - damageControl)