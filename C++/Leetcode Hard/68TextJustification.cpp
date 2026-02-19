class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res; 
        int z = 0;
        while (true) {
            int numChars = 0;
            vector<string> currLineVector;
            while (z < words.size() && numChars + currLineVector.size() + words[z].size() <= maxWidth) {
                currLineVector.push_back(words[z]);
                numChars += words[z].size();
                ++z;
            }

            int numGaps = currLineVector.size()-1;
            //Last Line
            if (numGaps == 0 || z == words.size()) {
                string currLineString = currLineVector[0];
                for (int i = 1; i < currLineVector.size(); ++i) {
                    currLineString += " ";
                    currLineString += currLineVector[i];
                }
                int totalWhiteSpaceAfterLastWord = maxWidth-currLineString.size();
                for (int i = 0; i < totalWhiteSpaceAfterLastWord; ++i) currLineString += " ";
                res.push_back(currLineString);
            }
            else {
                string currLineString = currLineVector[0];
                int totalWhiteSpace = maxWidth - numChars;
                int whiteSpacePerSpace = totalWhiteSpace / (max(1, (int)currLineVector.size()-1));
                int whiteSpaceRemainder = totalWhiteSpace % (max(1, (int)currLineVector.size()-1));

                for (int i = 1; i < currLineVector.size(); ++i) {
                    for (int j = 0; j < whiteSpacePerSpace; ++j) currLineString += " ";
                    if (whiteSpaceRemainder-- > 0) currLineString += " ";
                    currLineString += currLineVector[i];
                }

                res.push_back(currLineString);
            }
            if (z == words.size()) break;
        }
        return res; 
    }
};


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