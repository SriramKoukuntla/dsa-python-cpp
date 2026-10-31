class Node():
    def __init__(self):
        self.des = set() #all desendants
        set.has = set()
        self.children = [] #direct desendents

n, m = map(int, input().split())
nameToNode = {}

for _ in range(n):
    item1, statement, item2 = input().split()
    if item1 not in nameToNode:
        nameToNode[item1] = Node()
    node1 = nameToNode[item1]
    if statement == "has-a":
        node1.has.add(item2)
    elif statement == "is-a":
        if item2 not in nameToNode: 
            nameToNode[item2] = Node()
        node2 = nameToNode[item2]
        node2.children.append(node1)


#queries
for i in range(1, m+1):
    item1, statement, item2 = input().split()
    node1 = locator[item1]
    ret = "-1"
    if statement == "has-a":
        if node1.has(item2):
            ret = "true"
        else:
            ret = "false"
    else:
        if node2

    print("Query " + str(i) + ": " + ret)


#B isa A
#C isa A
#B isa C
#A = [B, C]
#C [B]