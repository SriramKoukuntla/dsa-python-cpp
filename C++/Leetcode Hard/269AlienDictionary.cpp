class Solution {
public:
    string alienOrder(vector<string>& words) {
        //Perform linear scan incase of early exit
        for (int i = 0; i < words.size()-1; ++i) {
            string currWord = words[i];
            string nextWord = words[i+1];

            int minLen = min(currWord.size(), nextWord.size());
            if (currWord.substr(0, minLen) == nextWord.substr(0, minLen) && nextWord.size() < currWord.size()) return "";
        }

        //Create innodes and adjlist
        unordered_map<char, int> indeg;
        for (string& word : words) for (char c : word) indeg[c] = 0;
        unordered_map<char, vector<char>> adjList;
        for (int i = 0; i < words.size()-1; ++i) {
            string& currString = words[i];
            string& nextString = words[i+1];
            for (int j = 0; j < (int)min(currString.size(), nextString.size()); ++j) {
                if (currString[j] != nextString[j]) {
                    ++indeg[nextString[j]];
                    adjList[currString[j]].push_back(nextString[j]);
                    break;
                }
            }
        }

        //Populate queue with letters with indegree of zero
        string res = "";
        deque<char> queue;
        for (auto [letter, currIndegree] : indeg) {
            if (currIndegree == 0) {
                queue.push_back(letter);
                res.push_back(letter);
            }
        }

        //Core alg of khan's algorithm
        while (!queue.empty()) {
            char currLetter = queue.front();
            queue.pop_front();

            for (char nextLetter : adjList[currLetter]) {
                if (--indeg[nextLetter] == 0) {
                    queue.push_back(nextLetter);
                    res.push_back(nextLetter);
                }
            }
        }

        //This will check for cycle
        for (auto [letter, currIndegree] : indeg) if (currIndegree != 0) return "";
        return res;
    }
};
//Linear scan to see if the first (min(a.length, b.length) characters match && a.size < b.size()) if not return ""
//Create hashmap that takes in chars and has indegree value
//Create hashmap that takes in chars and has list of elements it points to 
//Perform Khan's algorithm


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
