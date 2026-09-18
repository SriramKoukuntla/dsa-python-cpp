//This is for counting number of set bits (bits that are 1 not 0). O(b) where b is the number of set bits
int BrianKernigh(int n) {
    int res = 0;
    while (n != 0) {
        res &= n-1;
        +=res;
    }
    return res;
}
//This works before we only remove the last set bit each iteration, so we can just ++res on every iteration
//Ex: if n = 10, then
//1010 & 1001 -> 1000
//1000 & 0111 -> 0
//thus res = 2