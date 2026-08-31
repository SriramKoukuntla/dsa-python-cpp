#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string combined;
        for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
            combined += word1[i];
            combined += word2[i];
        }
        if (word1.size() > word2.size()) combined.insert(combined.end(), word1.begin() + word2.size(), word1.end());
        if (word1.size() < word2.size()) combined.insert(combined.end(), word2.begin() + word1.size(), word2.end());

        return combined;
    }
};

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