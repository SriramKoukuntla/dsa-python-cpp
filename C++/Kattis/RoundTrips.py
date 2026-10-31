#start 8:49
t = input()
def inside(p1, p2, p3): #return if p1 is inside p2 and p3 rectangle
    return p2[0] <= p1[0] <= p3[0] and p2[1] <= p1[1] <= p3[1]

def equation(p1, p2): #returns yintercept and slope
    slope = (p2[1] - p1[1]) / (p2[0] - p1[0])
    changeInX = 0 - p1[0]
    Yintercept = p1[1] + (changeInX * slope)
    return (Yintercept, slope)

def interceptY(p1, p2, x1): #y intercept of slope at x1
    YIntercept, Slope = equation(p1, p2)
    return x1 * Slope + YIntercept

def interceptX(p1, p2, y1): #X intercept of slope at y1
    YIntercept, Slope = equation(p1, p2)
    return (y1 - YIntercept) / Slope



for _ in range(t):
    bx1, by1, bx2, by2, x1, y1, x2, y2 = input().split()
    bStart = [bx1, by1]
    bEnd = [bx2, by2]
    dStart = [x1, y1]
    dEnd = [x2, y2]
    if (dStart[0] > dEnd[0]):
        dStart, dEnd = dEnd, dStart
    if (bStart[0] > bEnd[0]):
        bStart, bEnd = bEnd, bStart
    bIncreasing = bEnd[1] - bStart[1]
    dIncreasing = dEnd[1] - dStart[1]
    if (bIncreasing != dIncreasing):
        print((dEnd[0]-dStart[0]) + (dEnd[1]-dStart[1]))
        continue


    hopStart = -1
    hopEnd = -1
    leftBPointInside = inside(bStart, dStart, dEnd)
    rightBPointInside = inside(bEnd, dStart, dEnd)
    if (leftBPointInside):
        hopStart = bStart
    if (rightBPointInside):
        hopend = bEnd
    if (hopStart == -1):
        
        


        slope = (bEnd[1] - bStart[1]) / (bEnd[0] - bStart[0])
        changeInX = 



    
    ans = 0
    if leftPointInside:



    

