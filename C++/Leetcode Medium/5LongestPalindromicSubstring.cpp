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