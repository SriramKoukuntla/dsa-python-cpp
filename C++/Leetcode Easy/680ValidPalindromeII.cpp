class Solution {
public:
    bool validPalindrome(string s) {
        int index = 0;
        while (index < s.size()/2) {
            if (s[index] != s[s.size()-1-index]) break;
            index++;
        }
        if (index == s.size()/2) return true; 

        return isPalindrome(s, index+1, s.size()-1-index)
            || isPalindrome(s, index, s.size()-1-index-1);

    }

    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        int index = 0;
        while (index < s.size()/2) {
            if (s[index] != s[s.size()-1-index]) break;
            index++;
        }
        if (index == s.size()/2) return true; 

        int start = index+1; 
        int end = s.size()-1-index; 

        bool temp1 = true;
        while (start <= end) {
            if (s[start] != s[end]) {
                temp1 = false;
                break;
            }
            ++start;
            --end;
        }
        if (temp1) return true;

        start = index; 
        end = s.size()-1-index-1; 
        temp1 = true;
        while (start <= end) {
            if (s[start] != s[end]) {
                temp1 = false;
                break;
            }
            ++start;
            --end;
        }
        if (temp1) return true;
        return false;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size()-1, 0);
    }

    bool helper(string& s, int start, int end, int counter) {
        if (end-start <= 0) return true; //end-start = 0 means length of 1, end-start -1 means length of 0
        
        if (s[start] == s[end]) return helper(s, start+1, end-1, counter);
        if (counter == 1) return false;
        return helper(s, start+1, end, counter+1) || helper(s, start, end-1, counter+1);
    }
};

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