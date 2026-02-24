#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int j = 0;
        while (true) {
            char charToMatch = strs[0][j];
            for (int i = 0; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[i][j] != charToMatch) return strs[0].substr(0, j);
            }
            ++j;
        }
        return "";
    }
};