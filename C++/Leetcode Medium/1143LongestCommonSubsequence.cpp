#include <vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, 0, 0, mem);
    }

    int helper(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& mem) {
        if (idx1 >= text1.size() || idx2 >= text2.size()) return 0;
        if (mem[idx1][idx2] != -1) return mem[idx1][idx2];
        int res = 0;
        if (text1[idx1] == text2[idx2]) res = 1 + helper(text1, text2, idx1+1, idx2+1, mem);
        else {
            int skipText1 = helper(text1, text2, idx1+1, idx2, mem);
            int skipText2 = helper(text1, text2, idx1, idx2+1, mem);
            res = max(skipText1, skipText2);
        }
        mem[idx1][idx2] = res;
        return res;
    }
};

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i = text1.size()-1; i >= 0; --i){
            for (int j = text2.size()-1; j >= 0; --j){
                if (text1[i] == text2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};