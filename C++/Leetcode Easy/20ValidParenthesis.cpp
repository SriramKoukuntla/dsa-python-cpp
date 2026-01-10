#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push_back(s[i]);
            else {
                if (stack.empty()) return false;
                if (s[i] == ')' && stack.back() != '(') return false;
                else if (s[i] == ']' && stack.back() != '[') return false;
                else if (s[i] == '}' && stack.back() != '{') return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (char currChar : s){
            if (currChar == '(' || currChar == '[' || currChar == '{') stack += currChar;
            else {
                if (stack.empty()) return false;
                char popChar = stack.back();
                stack.pop_back();
                if ((currChar == ')' && popChar != '(') || 
                    (currChar == '}' && popChar != '{') || 
                    (currChar == ']' && popChar != '[')){
                    return false;
                } 
            }
        }
        return stack.empty();
    }
};