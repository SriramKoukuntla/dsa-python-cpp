#include <string>
#include <vector>
using namespace std;
class Solution {
public: 
    void helper(string& currString, int numOpen, int numClosed, int n, vector<string>& res) {
        if (numClosed > numOpen) return;
        if (numOpen + numClosed > n) return;
        if (numOpen + numClosed == n && numOpen == numClosed) {
            res.push_back(currString);
            return;
        }
        currString += "(";
        helper(currString, numOpen+1, numClosed, n, res);
        currString.pop_back();
        currString += ")";
        helper(currString, numOpen, numClosed+1, n, res);
        currString.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string currString = "";
        vector<string> res;
        helper(currString, 0, 0, n*2, res);
        return res;
    }
};