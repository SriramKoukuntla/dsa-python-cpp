    class Node:
        def __init__(self, isAnd):
            self.isAnd = isAnd
            self.children = []

    n, t = input().split()
    n = int(n)
    layers = [input().split() for _ in range(n)]
    tracker = [0 for __ in range(len(layers))]
    currAnd = (t == "A")

    def constructTree(i, j, currAnd):
        global layers, tracker
        if (layers[i][j] == "T" or layers[i][j] == "F"): return layers[i][j]
        currNode = Node(currAnd)
        numChildren = int(layers[i][j])
        for _ in range(numChildren): 
            childIndex = tracker[i + 1]
            tracker[i + 1] += 1

            child = constructTree(i + 1, childIndex, not currAnd)
            currNode.children.append(child)
        return currNode 

    root = constructTree(0, 0, currAnd)

    def verdect(node):
        if (node == "T"): return True
        if (node == "F"): return False
        if (node.isAnd):
            for child in node.children:
                if (not verdect(child)): return False
            return True
        else:
            for child in node.children:
                if (verdect(child)): return True
            return False

    evaluated = verdect(root)

    def flip(node, evaluateTo):
        if (node == "T"):
            if (evaluateTo): return 0
            else: return 1
        if (node == "F"):
            if (evaluateTo): return 1
            else: return 0
        if (node.isAnd):
            if (evaluateTo):
                sum = 0
                for child in node.children: sum += flip(child, evaluateTo)
                return sum
            else:
                res = float("inf")
                for child in node.children: res = min(res, flip(child, evaluateTo))
                return res
        else:
            if (evaluateTo):
                res = float("inf")
                for child in node.children: res = min(res, flip(child, evaluateTo))
                return res
            else:
                sum = 0
                for child in node.children: sum += flip(child, evaluateTo)
                return sum

    ans = flip(root, not evaluated)
    print(ans)