#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for (int i = 0; i < s.length(); ++i){
            if (isalnum(s[i])) newS += tolower(s[i]);
        }
        for (int i = 0; i < newS.length()/2; ++i){
            if (newS[i] != newS[newS.length() - 1- i]) return false;
        }
        return true;
    }
};

#include <string>
#include <cctype>
using namespace std;

class Solution{
public: 
    bool isPalindrome(string s){
        string newString;
        for (char currChar : s){
            if (isalnum(currChar)){
                newString += tolower(currChar);
            }
        }
        for (int i = 0; i < newString.size()/2; ++i){
            if (newString[i] != newString[newString.size()-i-1]) return false;
        }
        return true;
    }
};