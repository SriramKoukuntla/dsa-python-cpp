#include <string>
#include <vector>

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector(s.size(), false));
        int res = 0;
        for (int i = s.size(); i >= 0; --i){
            for (int j = i; j < s.size(); ++j){
                if (s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};