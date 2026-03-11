//Backtracking Solution
class Solution {
public:
    void helper(vector<string>& res, vector<vector<char>>& digitToLetter, int i, string& digits, string& tempString) {
        if (i == digits.size()) {res.push_back(tempString); return;}
    
        for (char digit : digitToLetter[digits[i]-'0']) {
            tempString.push_back(digit);
            helper(res, digitToLetter, i+1, digits, tempString);
            tempString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char>> digitToLetter = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        string tempString = "";
        helper(res, digitToLetter, 0, digits, tempString);
        return res;
    }
};

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void helper(string& digits, vector<string> currentCombinations, vector<string>& res, int i, vector<vector<char>>& digitToLetter) {
        if (i == digits.size()) {
            res.insert(res.end(), currentCombinations.begin(), currentCombinations.end());
            return;
        }
        vector<string> nextCombinations;
        char digit = digits[i];
        for (char currChar: digitToLetter[digit-'0']) {
            for (string& combination : currentCombinations) {
                nextCombinations.push_back(combination + currChar);
            }
        }
        helper(digits, nextCombinations, res, i+1, digitToLetter);

    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> currentCombinations = {""};
        vector<vector<char>> digitToLetter = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        helper(digits, currentCombinations, res, 0, digitToLetter);
        return res;
    }
};