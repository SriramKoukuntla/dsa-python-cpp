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