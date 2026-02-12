#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res; 
        vector<string> wordsOnCurrLine;
        int charsLeft = maxWidth;
        for (int i = 0; i < words.size(); ++i) {
            if (!wordsOnCurrLine.empty()) --charsLeft;
            charsLeft -= words[i].size();
            wordsOnCurrLine.push_back(words[i]);
            if (i == words.size()-1) {
                string lastLine = "";
                for (int j = 0; j < wordsOnCurrLine.size(); ++j) {
                    lastLine += wordsOnCurrLine[j];
                    if (j != wordsOnCurrLine.size()-1) lastLine += " ";
                }
                int n = maxWidth-lastLine.size();
                for (int j = 0; j < n; ++j) lastLine += " ";
                res.push_back(lastLine);
            }
            if (i != words.size()-1 && charsLeft < words[i+1].size() + 1) {
                res.push_back(currLineString(wordsOnCurrLine, charsLeft, maxWidth));
            }
        }
        return res;
    }
private:
    string currLineString(vector<string>& wordsOnCurrLine, int& charsLeft, int maxWidth) {
        string res = "";
        if (wordsOnCurrLine.size() == 1) {
            res += wordsOnCurrLine[0];
            for (int i = 0; i < maxWidth-wordsOnCurrLine[0].size(); ++i) res += " ";
        }
        else {
            int numSpaces = wordsOnCurrLine.size()-1;
            int numExtraSpacesBetweenWords = charsLeft / numSpaces;
            int spacesLeftOver = charsLeft % numSpaces;
            for (int i = 0; i < wordsOnCurrLine.size(); ++i) {
                string currWord = wordsOnCurrLine[i];
                res += currWord;
                if (i != wordsOnCurrLine.size()-1) {
                    res += " ";
                    for (int i = 0; i < numExtraSpacesBetweenWords; ++i) res += " ";
                }
                if (spacesLeftOver-- > 0) res += " ";
            }
        }
        wordsOnCurrLine = {};
        charsLeft = maxWidth;
        return res;   
    }
};