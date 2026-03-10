class Solution {
public:
    string minWindow(string s, string t) {
        //Count frequency of letters in t
        unordered_map<char, int> tFreq;
        for (char c : t) ++tFreq[c];
        int uniqueLettersT = tFreq.size();

        //Sliding window algorithm
        unordered_map<char, int> windowFreq;
        int numUniqueLettersFitCondition = 0;
        int resLength = s.size();
        int resStart = -1;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (++windowFreq[s[r]] == tFreq[s[r]]) ++numUniqueLettersFitCondition;

            //Making window smaller whenever it's valid
            while (numUniqueLettersFitCondition == uniqueLettersT) {
                    if (r-l+1 <= resLength) { //updating res for every valid window if smaller than previously seen
                        resLength = r-l+1;
                        resStart = l;
                    }
                    ++l;
                    if (--windowFreq[s[l-1]] < tFreq[s[l-1]]) --numUniqueLettersFitCondition;
            }
        }

        return (resStart == -1) ? "" : s.substr(resStart, resLength);
    }
};


#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkWindow(unordered_map<char, long long>& sCharFreq, unordered_map<char, long long>& windowCharFreq) {
        for (auto [c, f] : sCharFreq) if (windowCharFreq[c] < f) return false;
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, long long> tCharFreq;
        for (char c : t) ++tCharFreq[c];

        int resL = -1;
        int resR = -1;

        unordered_map<char, long long> windowCharFreq;
        int counter = 0;
        int l = 0; 
        for (int r = 0; r < s.size(); ++r) {
            if (tCharFreq[s[r]] == ++windowCharFreq[s[r]]) {
                if (checkWindow(tCharFreq, windowCharFreq)) {
                    if (resL == -1 || r-l+1 < resR-resL+1) {resR = r; resL = l;};


                    while (tCharFreq[s[l]] != --windowCharFreq[s[l++]] + 1) {
                        if (resL == -1 || r-l+1 < resR-resL+1) {resR = r; resL = l;};

                    }
                }
            }

        }
        return (resL == -1) ? "" : s.substr(resL, resR-resL+1);        
    }
};