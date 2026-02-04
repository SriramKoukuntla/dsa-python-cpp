class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> mem(coins.size(), vector<int>(amount+1, -2));
        return helper(coins, amount, 0, 0, mem);
    }

    int helper(vector<int>& coins, int amount, int i, int currSum, vector<vector<int>>& mem) {
        if (currSum == amount) return 0;
        if (i >= coins.size()) return -1;    
        if (currSum > amount) return -1;
        if (mem[i][currSum] != -2) return mem[i][currSum];


        int stay = helper(coins, amount, i, currSum + coins[i], mem);
        if (stay != -1) ++stay;
        int next = helper(coins, amount, i+1, currSum, mem);
        
        int res = 0;
        if (stay == -1 && next == -1) res = -1;
        else if (stay == -1) res = next;
        else if (next == -1) res = stay;
        else res = min(stay, next);
        mem[i][currSum] = res;
        return res;
    }
};


#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+1, amount+1);
        mem[0] = 0;
        for (int i = 1; i < amount+1; ++i) {
            for (int coin : coins) {
                if (coin <= i) mem[i] = min(mem[i], mem[i-coin]+1);
            }
        }
        return mem[amount] == amount+1 ? -1 : mem[amount];
    }
};
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