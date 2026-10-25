n, m, a, c, xS = map(int, input().split())
sequence = []
prev = xS
for i in range(n):
    val = ((prev * a) + c) % m
    sequence.append(val)
    prev = val

def binarySearch(sequence, target):
    l = 0
    r = len(sequence)-1
    mid  = l + ((r-l)//2)
    while (l <= r):
        mid  = l + ((r-l)//2)
        if (sequence[mid] == target): return True
        elif (target < sequence[mid]): r = mid-1
        elif (target > sequence[mid]): l = mid +1
    return False

res = 0
setSequence = set(sequence)
for val in setSequence:
    if (binarySearch(sequence, val)): 
        res += 1
print(res)