#start 12:14
n = int(input())
volume = []

while len(volume) < n:
    volume += list(map(int, input().split()))

stack = [] #strictly increasing

start = -1
end = -1
res = float("-inf")

for i in range(n):
    if len(stack) == 0 or stack[-1][0] < volume[i]:
        stack.append((volume[i], i))
        continue
    lastIndexVal = -1
    while (len(stack) != 0 and stack[-1][0] >= volume[i]):
        lastItem = stack.pop()
        tempStart = lastItem[1]
        tempEnd = i
        tempVal = lastItem[0]
        tempRes = (tempEnd-tempStart) * (tempVal)
        if tempRes > res or (tempRes == res and tempStart+1 < start):
            # print(str(tempStart) + ", " + str(tempEnd) + ", " + str(tempVal) + ", " + str(tempRes))
            res = tempRes
            start = tempStart + 1
            end = tempEnd
        lastIndexVal = lastItem[1]
    stack.append((volume[i], lastIndexVal))

for i in range(len(stack)):
    currItem = stack.pop()
    tempStart = currItem[1]
    tempEnd = n
    tempVal = currItem[0]
    tempRes = (tempEnd-tempStart) * (tempVal)
    if tempRes > res or (tempRes == res and tempStart+1 < start):
        # print(str(tempStart) + ", " + str(tempEnd) + ", " + str(tempVal) + ", " + str(tempRes))
        start = tempStart + 1
        end = tempEnd
        res = tempRes

print(str(start) + " " + str(end) + " " + str(res))