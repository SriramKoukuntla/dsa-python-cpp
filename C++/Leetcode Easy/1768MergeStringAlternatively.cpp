#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
            res += word1[i];
            res += word2[i];
        }
        if (word1.size() > res.size()/2) res += word1.substr(res.size()/2);
        if (word2.size() > res.size()/2) res += word2.substr(res.size()/2);
        return res;
    }
};