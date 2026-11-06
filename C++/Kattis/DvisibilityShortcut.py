#start 6:27
#trying to do 5, 45
#base 2 === 1111
#base 3 === 120
#base 4 === 33
#base 5 === 30
#base 6 = 23, 113

T = int(input())

for _ in range(T):
    b, k = map(int, input().split())
    for i in range(k, 0, -1):
        output = False
        if b % i == 1:
            print(i)
            output = True
            break
    if not output:
        print("1")

    

