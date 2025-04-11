class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for i in range(low, high+1):
            strV = str(i)
            if len(strV) % 2 == 1:
                continue
            c = 0
            for j in range(len(strV)//2):
                c += int(strV[j])
                c -= int(strV[len(strV)-1-j])
            if c == 0:
                print(i)
                count += 1
        return count