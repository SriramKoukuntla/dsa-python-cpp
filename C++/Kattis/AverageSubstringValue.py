s = input()
n = len(s)

stack = []
currSum = 0
totalSum = 0

for c in s:
    digit = int(c)
    count = 1

    while stack and stack[-1][0] <= digit:
        val, cnt = stack.pop()
        currSum -= val * cnt
        count += cnt

    stack.append((digit, count))
    currSum += digit* count
    totalSum += currSum
totalSubstrings = n * (n+1) // 2
ans = totalSum / totalSubstrings
print(ans)