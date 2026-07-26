#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        //Iterate through string. If we reach I, X, C we check if V/X, L/C, D/M is after because that's a unique value
        //Calculate sum throughout iteration
        int res = 0;

        unordered_map<char, int> LetterToNum = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
        {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size(); ++i) {
            char currChar = s[i];
            if (i != s.size()-1 && LetterToNum[s[i+1]] > LetterToNum[currChar]) {
                res += (LetterToNum[s[i+1]] - LetterToNum[currChar]);
                ++i;
            }
            else res += LetterToNum[currChar];
        }
        return res;   
    }
};