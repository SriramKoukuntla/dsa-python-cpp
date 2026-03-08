class Solution {
public:
    int helper(int i, int j, unordered_map<int, int>& mem) {
        if (i == 0 && j == 0) return 1;
        int currHash = i * 100 + j;
        if (mem.find(currHash) != mem.end()) return mem[currHash];
        int res = 0;
        res += (i == 0) ? 0 : helper(i-1, j, mem);
        res += (j == 0) ? 0 : helper(i, j-1, mem);
        mem[currHash] = res;
        return res;
    }

    int uniquePaths(int m, int n) {
        unordered_map<int, int> mem;
        return (helper(m-1, n-1, mem));
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathPossibilities(m, vector<int>(n, 0));
        pathPossibilities[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                int upVal = (i-1 < 0) ? 0 : pathPossibilities[i-1][j];
                int leftVal = (j-1 < 0) ? 0 : pathPossibilities[i][j-1];
                pathPossibilities[i][j] = upVal + leftVal;
            }
        }
        return pathPossibilities[m-1][n-1];
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, 0));
        mem[0][0] = 1;
        for (int i = 0; i < mem.size(); ++i){
            for (int j = 0; j < mem[0].size(); ++j){
                if (i > 0) mem[i][j] += mem[i-1][j];
                if (j > 0) mem[i][j] += mem[i][j-1];
            }
        }
        return mem[m-1][n-1];
    }
};