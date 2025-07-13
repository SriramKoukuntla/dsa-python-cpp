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