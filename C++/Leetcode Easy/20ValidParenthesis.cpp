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