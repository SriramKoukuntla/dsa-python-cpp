class Solution {
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size()-1, 0);
    }
    bool helper(string& s, int start, int end, int count) {
        if (count >= 2 || end < 0 || start == s.size()) return false;
        if (end-start <= 0) return true;
        if (s[start] == s[end]) return helper(s, start+1, end-1, count);
        return helper(s, start+1, end, count+1) || helper(s, start, end-1, count+1);
    }
};