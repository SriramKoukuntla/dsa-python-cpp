#include <string>
#include <list>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        string S;
        for (char c : s) if (c != ' ') S.push_back(c);

        list<string> expression;
        int i = 0;
        while (i < S.size()) {
            if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') expression.push_back(string(1, S[i++]));
            else {
                string subStr;
                while (i < S.size() && isdigit(S[i])) subStr += S[i++];
                expression.push_back(subStr);
            }
        }

        for (auto it = expression.begin(); it != expression.end(); ++it) {
            string op = *it;
            if (op != "*" && op != "/") continue;
            auto temp = (it);
            --temp;
            int prevVal = stoi(*temp);
            expression.erase(temp);

            temp = it;
            ++it;
            expression.erase(temp);

            *it = (op == "*") ? to_string(prevVal * stoi(*it)) : to_string(prevVal / stoi(*it));
        }


        for (auto it = expression.begin(); it != expression.end(); ++it) {
            string op = *it;
            if (op != "+" && op != "-") continue;
            auto temp = (it);
            --temp;
            int prevVal = stoi(*temp);
            expression.erase(temp);

            temp = it;
            ++it;
            expression.erase(temp);

            *it = (op == "+") ? to_string(prevVal + stoi(*it)) : to_string(prevVal - stoi(*it));
        }

        return stoi(expression.front());
    }
};