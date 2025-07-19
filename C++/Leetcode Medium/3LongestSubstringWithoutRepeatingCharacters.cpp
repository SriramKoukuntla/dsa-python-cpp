#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> letters;
        int back = 0;
        for (int front = 0; front < s.size(); ++front){
            while(letters.find(s[front]) != letters.end()){
                letters.erase(s[back]);
                ++back;
            }
            letters.insert(s[front]);
            res = max(res, front-back+1);
        }
        return res;
    }
};