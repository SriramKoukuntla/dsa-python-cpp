#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        //Calculate Hash of each word
        int MOD = 1000000007;
        vector<int> hashedStrings;
        for (string& word : dict) {
            int currHash = 0;
            for (char c : word) currHash = ((1LL * currHash * 26) + (c-'a')) % MOD;
            hashedStrings.push_back(currHash);
        }

        //Core algorithm
        int multiplier = 1;
        for (int j = dict[0].size()-1; j >= 0; --j) {
            unordered_map<int, vector<int>> map;
            for (int i = 0; i < dict.size(); ++i) {
                int currHash = hashedStrings[i];
                int removedContribution = (1LL * multiplier * (dict[i][j]-'a')) % MOD;
                currHash = (1LL * MOD + currHash - removedContribution) % MOD;
                for (int z : map[currHash]) {
                    string s = dict[z];
                    if (s.substr(0, j) == dict[i].substr(0, j)
                     && s.substr(j+1, s.size()-1-j) == dict[i].substr(j+1, dict[i].size()-1-j)) return true;
                }
                map[currHash].push_back(i);
            }
            multiplier = (1LL * multiplier * 26) % MOD;
        }
        return false;        
    }
};