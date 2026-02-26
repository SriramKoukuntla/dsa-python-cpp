class Solution {
public:
    string longestPalindrome(string s) {
        //Preprocessing string s
        string sPrime;
        for (int i = 0; i < s.size(); ++i) sPrime += (i == 0) ? "*" + string(1, s[i]) + "*" : string(1, s[i]) + "*";

        //Tracking information initialization
        vector<int> radius(sPrime.size(), 0);
        int c = 0;
        int r = 0;
        int maxRadius = 0;
        int largestPalindromeCenter = 0;

        //Core algorithm
        for (int i = 0; i < sPrime.size(); ++i) {
            //If we are in a larger palindrome
            int mirrorIndex = c-(i-c);
            if (i < r) radius[i] = min(radius[mirrorIndex], r-i);

            //Keep checking if palindrome beyond current radius
            while (i-radius[i]-1 >=0 && i+radius[i]+1 < sPrime.size() && sPrime[i-radius[i]-1] == sPrime[i+radius[i]+1]) ++radius[i];

            //update c and r
            if (i + radius[i] > r) {
                c = i;
                r = i + radius[i];
            }

            //Update our res tracking information
            if (radius[i] > maxRadius) {
                maxRadius = radius[i];
                largestPalindromeCenter = i;
            }
        }
        int start = (largestPalindromeCenter - maxRadius) / 2;
        return s.substr(start, maxRadius);
    }
};

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool helper(int i, int j, string& s, unordered_map<int, bool>& mem) {
        if (i == j) return true;
        if (i + 1 == j && s[i] == s[j]) return true;
        int currHash = (i * (int)s.size()) + j;
        if (mem.find(currHash) != mem.end()) return mem[currHash];
        if (s[i] == s[j]) {
            bool res = helper(i+1, j-1, s, mem);
            mem[currHash] = res;
            return res;
        }
        else return false;
    }

    string longestPalindrome(string s) {
        int l = 0;
        int r = 0;
        unordered_map<int, bool> mem;
        for (int i = 0; i < (int)s.size(); ++i) {
            for (int j = i; j < (int)s.size(); ++j) {
                if (helper(i, j, s, mem)) {
                    if (j-i+1 > r-l+1) {
                        l = i;
                        r = j;
                    }
                }
            }
        }
        return s.substr(l, r-l+1); 
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        //Check for odd lengths
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            int l = i;
            int r = i;
            while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l;
            --r;
            if (r-l+1 > res.size()) res = s.substr(l, r-l+1);
        }
        //Check for even lengths
        for (int i = 0; i < s.size()-1; ++i) {
            int l = i;
            int r = i+1;
            while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l;
            --r;
            if (r-l+1 > res.size()) res = s.substr(l, r-l+1);
        }
        return res;
    }
};

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