#include <unordered_map>
#include <string>
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