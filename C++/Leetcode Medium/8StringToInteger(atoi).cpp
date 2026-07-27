#include <unordered_map>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        unordered_map<char, int> charToInt = {{'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
         {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'0', 0}};
        long long res = 0;
        int idx = 0;

        while (s[idx] == ' ') if (++idx == s.size()) return 0;

        bool boolIsNeg = (s[idx] == '-');
        if (s[idx] == '-' || s[idx] == '+') if (++idx == s.size()) return 0;

        while (s[idx] == '0') if (++idx == s.size()) return 0;

        while(charToInt.find(s[idx]) != charToInt.end()) {
            res *= 10;
            if (boolIsNeg) res -= charToInt[s[idx]];
            else res += charToInt[s[idx]];
            if (boolIsNeg && res < INT_MIN) return INT_MIN;
            if (!boolIsNeg && res > INT_MAX) return INT_MAX; 
            ++idx;
        }

        return res;    
    }
};
