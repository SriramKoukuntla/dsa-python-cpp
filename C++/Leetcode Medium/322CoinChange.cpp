#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> mem(amount+1, -1);
        mem[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int temp = 10000000;
            for (int coin : coins) {
                if (coin > amount) break;
                else if (coin <= i) {
                    if (mem[i-coin] != -1) temp = min(temp, mem[i-coin] + 1);
                }
            }
            mem[i] = temp == 10000000 ? -1 : temp;
        }
        return mem[amount];
    }
};