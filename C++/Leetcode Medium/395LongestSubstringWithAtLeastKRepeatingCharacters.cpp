#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int helper(string& s, int l, int r, int k) { //l is inclusive, r is exclusive
        //Count Global Frequency
        vector<int> globalFreq(26, 0);
        for (int i = l; i < r; ++i) ++globalFreq[s[i]-'a'];

        //Check if it's even a valid string
        bool validString = false;
        for (int freq : globalFreq) if (freq >= k) validString = true;
        if (!validString) return 0;

        //Create array which tracks ranges of subproblems
        vector<int> invalidCharIdxs = {l-1};
        for (int i = l; i < r; ++i) if (globalFreq[s[i]-'a'] < k) invalidCharIdxs.push_back(i);
        invalidCharIdxs.push_back(r);
        
        int res = 0;
        if (invalidCharIdxs.size() > 2) {
            for (int i = 0; i < invalidCharIdxs.size()-1; ++i) res = max(res, helper(s, invalidCharIdxs[i]+1, invalidCharIdxs[i+1], k));
            return res;
        }
        else return r-l;
    }

    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
};