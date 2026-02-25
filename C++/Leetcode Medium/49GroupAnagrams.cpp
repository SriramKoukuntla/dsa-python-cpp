#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); ++i) {
            vector<int> alphaFreq(26, 0);
            for (int j = 0; j < strs[i].size(); ++j) ++alphaFreq[strs[i][j]-'a'];
            string currHash = "";
            for (int freq : alphaFreq) currHash += to_string(freq) + ",";
            map[currHash].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto& [sortedString, listOfStrings] : map) {
            res.push_back(listOfStrings);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); ++i){
            string word = strs[i];
            string sortedString = word;
            sort(sortedString.begin(), sortedString.end());
            map[sortedString].push_back(word);
        }
        vector<vector<string>> res;
        for (auto& pair : map){
            res.push_back(pair.second);
        }
        return res;
    }
};