#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool helper(string& s, string& p, int si, int pi, vector<vector<char>>& mem) {
        if (mem[si+1][pi+1] != -1) return mem[si+1][pi+1];
        bool res = false;
        if (si == -1 && pi == -1) res = true;
        else if (pi == -1) res = false;
        else if (p[pi] != '*' && p[pi] != '.') res = (si < 0 || s[si] != p[pi]) ? false : helper(s, p, si-1, pi-1, mem);
        else if (p[pi] == '.') res = (si < 0) ? false : helper(s, p, si-1, pi-1, mem);
        else if (p[pi] == '*') {
            //Don't use character
            res = res || helper(s, p, si, pi-2, mem);
            if (res) return res;
            //Use character
            if ((si != -1) && (p[pi-1] == '.' || s[si] == p[pi-1])) res = res || helper(s, p, si-1, pi, mem);
        }

        mem[si+1][pi+1] = res ? 1 : 0;
        return res;
    }


    bool isMatch(string s, string p) {
        vector<vector<char>> mem(s.size()+1, vector<char>(p.size()+1, -1));
        return helper(s, p, s.size()-1, p.size()-1, mem);
    }
};