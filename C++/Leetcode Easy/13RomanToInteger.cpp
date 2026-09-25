#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int index = 0;
        unordered_map<string, int> convert;
        convert["I"] = 1;
        convert["V"] = 5;
        convert["X"] = 10;
        convert["L"] = 50;
        convert["C"] = 100;
        convert["D"] = 500;
        convert["M"] = 1000;
        convert["IV"] = 4;
        convert["IX"] = 9;
        convert["XL"] = 40;
        convert["XC"] = 90;
        convert["CD"] = 400;
        convert["CM"] = 900;

        while (index < s.size()) {
            if (index + 1 < s.size()) {
                string firstTwo = s.substr(index, 2);
                if (convert.find(firstTwo) != convert.end()) {
                    res += convert[firstTwo];
                    index += 2;
                    continue;
                }
            }
            res += convert[string(1, s[index])];
            index += 1;
        }
        return res;

    }
};

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