#include <vector>
using namespace std;
class Solution {
public:
    int helper(int n, int maxWidth, vector<vector<int>>& mem) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (maxWidth == 0) return 0;
        if (mem[n][maxWidth] != -1) return mem[n][maxWidth];

        int res = 0;
        int maxCardsCurrLayer = (3*maxWidth)-1;

        for (int i = 2; i <= n && i <= maxCardsCurrLayer; i += 3) {
            int nextWidth = (i+1)/3;
            res += helper(n-i, nextWidth-1, mem);
        }
        mem[n][maxWidth] = res;
        return res;
    }

    int houseOfCards(int n) {
        int maxWidth = (n+1)/3;
        vector<vector<int>> mem(n+1, vector<int>(maxWidth+1, -1));
        return helper(n, maxWidth, mem);
    }
};