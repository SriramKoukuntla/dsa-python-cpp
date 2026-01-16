#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int res = 0;
        int l = 0;
        int maxFreq = 0;
        for (int r = 0; r < s.size(); ++r){
            map[s[r]] += 1;
            maxFreq = max(maxFreq, map[s[r]]);
            while (r-l+1-maxFreq > k){
                map[s[l]] -= 1;
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
}

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r){
            map[s[r]] += 1;
            while (r-l+1-map[mostFreq(map)] > k){
                map[s[l]] -= 1;
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }

    char mostFreq (unordered_map<char, int>& map){
        char mostOccurChar;
        int mostOccurFreq = 0;
        for (auto [c, i] : map){
            if (i > mostOccurFreq) {
                mostOccurChar = c;
                mostOccurFreq = i;
            }
        }
        return mostOccurChar;
    }
};

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r){
            map[s[r]] += 1;
            while (r-l+1-map[mostFreq(map)] > k){
                map[s[l]] -= 1;
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }

    char mostFreq (unordered_map<char, int>& map){
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYUZ";
        char mostOccur = 'A';
        for (int i = 0; i < alphabet.size(); ++i) {
            if (map[mostOccur] < map[alphabet[i]]) mostOccur = alphabet[i];
        }
        return mostOccur;
    }
};