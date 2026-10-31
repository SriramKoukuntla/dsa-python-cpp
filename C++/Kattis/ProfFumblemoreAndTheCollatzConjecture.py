import sys
input = input()

#check if valid
for i in range(0, len(input)):
    if (input[i] != "E" and input[i] != "O"):
        print("INVALID")
        sys.exit()

    if i != 0 and input[i] == "O" and input[i-1] == "O":
        print("INVALID")
        sys.exit()

if (input[-1] != "O"):
    print("INVALID")
    sys.exit()


start = 2
end = 2 ** 47

def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

while start <= end:
    currNum = start
    valid = True
    for i in range(len(input) - 1, -1, -1):     
        if i != len(input)-1 and is_power_of_two(currNum):
            valid = False
            break
        if currNum <= 1:
            valid = False
            break
        if currNum % 1 != 0:
            valid = False
            break
        char = input[i]

        if char == "O":
            if (currNum - 1) % 3 != 0:
                valid = False
                break

            currNum = (currNum - 1) // 3

            if currNum <= 1 or currNum % 2 == 0:
                valid = False
                break
        else:
            currNum *= 2


    if valid:
        print(int(currNum))
        sys.exit()
    start *= 2
print("INVALID")
sys.exit()
