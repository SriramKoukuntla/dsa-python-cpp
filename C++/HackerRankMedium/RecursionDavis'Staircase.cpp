#include <vector>
using namespace std;

int helper(int n, vector<int>& mem) {
    if (n == 0) return 1;
    else if (n == 1)  return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    else if (mem[n] != -1) return mem[n];
    else {
        int res = (helper(n-1, mem) + helper(n-2, mem) + helper(n-3, mem)) % 10000000007;
        mem[n] = res;
        return res;
    }
}


int stepPerms(int n) {
    vector<int> mem(n+1, -1);
    return helper(n, mem);
}