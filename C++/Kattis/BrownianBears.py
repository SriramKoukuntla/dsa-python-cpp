#start 4:12
from fractions import Fraction
n, x, y, d = list(map(int, input().split()))
x, y = x-1, y-1
joint = [[Fraction(0, 1)] * n for _ in range(n)]
joint[x][y] = Fraction(1, 1)

res = Fraction(0, 1)
for _ in range(d):
    newJoint = [[Fraction(0, 1)] * n for _ in range(n)]
    for i in range(len(joint)):
        res += joint[i][i]
        joint[i][i] = Fraction(0, 1)
    
    for i in range(len(joint)):
        for j in range(len(joint)):
            div = joint[i][j]/4
            newIUp = min(i+1, n-1)
            newIDown = max(i-1, 0)
            newJRight = min(j+1, n-1)
            newJLeft = max(j-1, 0)
            newJoint[newIUp][newJRight] += div
            newJoint[newIUp][newJLeft] += div
            newJoint[newIDown][newJRight] += div
            newJoint[newIDown][newJLeft] += div
    joint = newJoint

    for i in range(len(joint)):
        res += joint[i][i]
        joint[i][i] = Fraction(0, 1)

resNumerator = res.numerator
resDenominator = res.denominator
resPrint = str(resNumerator) + "/" + str(resDenominator)
print(resPrint)