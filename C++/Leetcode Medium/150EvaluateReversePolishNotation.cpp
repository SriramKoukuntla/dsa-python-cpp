#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (int i = 0; i < tokens.size(); ++i) {
            string curr = tokens[i];
            if (curr == "+" || curr == "-" || curr == "*" || curr == "/") {
                int val1 = stack.back();
                stack.pop_back();
                int val2 = stack.back();
                stack.pop_back();
                if (curr == "+") stack.push_back(val2 + val1);
                else if (curr == "-") stack.push_back(val2 - val1);
                else if (curr == "/") stack.push_back(val2 / val1);
                else if (curr == "*") stack.push_back(val2 * val1);
            }
            else {
                stack.push_back(stoi(curr));
            }
        }
        return stack.back();
    }
};