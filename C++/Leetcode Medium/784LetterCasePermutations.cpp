#include <vector>
#include <string>
#include <cctype> 
using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(s, 0, res);
        return res;
    }

    void helper(string& s, int i, vector<string>& res) {
        if (i >= s.size()) {res.push_back(s); return;}
        if (isdigit(s[i])) {helper(s, i+1, res); return;}
        s[i] = tolower(s[i]);
        helper(s, i+1, res);
        s[i] = toupper(s[i]);
        helper(s, i+1, res);
        return;
    }
};