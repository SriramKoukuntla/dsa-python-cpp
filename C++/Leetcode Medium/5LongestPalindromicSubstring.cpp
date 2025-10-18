#include <vector>
#include <string>
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector(s.size(), false));
        
        string res = "";
        for (int i = s.size()-1; i >= 0; --i){
            for (int j = i; j < s.size(); ++j){
                if (s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if (res.size() < j-i+1) res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};

#include <vector>
#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++i){
            int j = 0;
            while (i-j >= 0 && i+j < s.size()){
                if (s[i-j] != s[i+j]) break;
                if(res.size() < (i+j) - (i-j) + 1) res = s.substr(i-j, 2*j+1); 
                ++j;
            }
        }

        string res2 = "";
        for (int i = 0; i < s.size()-1; ++i){
            int j = 0;
            while (i-j >= 0 && i+1+j < s.size()){
                if (s[i-j] != s[i+1+j]) break;
                if(res2.size() < (i+j) - (i-j) + 2) res2 = s.substr(i-j, 2*j+2); 
                ++j;
            }
        }

        return res.size() > res2.size() ? res : res2;
    }
};