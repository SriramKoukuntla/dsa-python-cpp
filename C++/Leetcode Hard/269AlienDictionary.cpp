#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        for (int i = 0; i < words.size()-1; ++i) {
            if (words[i].size() > words[i+1].size() 
                && words[i].substr(0, words[i+1].size()) == words[i+1]) {
                return "";
            }
        }

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;

        unordered_set<char> characters;
        for (string word : words) for (char c : word) characters.insert(c);
        for (char c : characters) indeg[c] = 0;


        for (int i = 0; i < words.size()-1; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (words[i][j] != words[i+1][j]) {
                    adj[words[i][j]].push_back(words[i+1][j]);
                    ++indeg[words[i+1][j]];
                    break;
                }
            }
        }

        list<char> queue;
        string res = "";
        for (auto it = indeg.begin(); it != indeg.end(); ++it) {
            if (it->second == 0) {
                queue.push_back(it->first);
                res += it->first;
            }
        }


        while (!queue.empty()) {
            char curr = queue.front();
            queue.pop_front();
            for (char rem : adj[curr]) {
                if (--indeg[rem] == 0) {
                    queue.push_back(rem);
                    res += rem;
                }
            }
        }

        for (auto [character, indegreeValue] : indeg) if (indegreeValue) return "";
        return res;
    }
};
