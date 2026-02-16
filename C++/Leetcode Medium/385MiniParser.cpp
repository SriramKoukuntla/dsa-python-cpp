/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
#include <string>
#include <vector>
using namespace std;
class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class Solution {
public:
    bool isNum(string s) {
        int i = 0;
        if (s[i] == '-') ++i;
        while (i < s.size()) if (!isdigit(s[i++])) return false;
        return true;
    }
    NestedInteger deserialize(string s) {
        if (isNum(s)) return NestedInteger(stoi(s));

        NestedInteger res = NestedInteger();
        int i = 1;
        string substring;
        while (i < s.size()-1) {
            if (s[i] == ',' || s[i] == ' ') ++i;
            else if (s[i] == '-' || isdigit(s[i])) {
                while (i < s.size()-1 && (s[i] == '-' || isdigit(s[i]))) {
                    substring += s[i];
                    ++i;
                }
                NestedInteger temp = NestedInteger(stoi(substring));
                res.add(temp);
                substring = "";
            }
            else if (s[i] == '[') {
                int openingBrackets = 1;
                substring += s[i];
                ++i;
                while (i < s.size()-1 && openingBrackets) {
                    substring += s[i];
                    if (s[i] == '[') ++openingBrackets;
                    else if (s[i] == ']') --openingBrackets;
                    ++i;
                }
                res.add(deserialize(substring));
                substring = "";
            }
        }
        return res;

    }
};