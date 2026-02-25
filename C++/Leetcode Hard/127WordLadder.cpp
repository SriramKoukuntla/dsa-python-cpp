#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Creating newWordList
        unordered_map<string, vector<string>> newWordList;
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < wordList[i].size(); ++j) {
                string tempString = wordList[i].substr(0, j) + "*" + wordList[i].substr(j+1, wordList[i].size());
                newWordList[tempString].push_back(wordList[i]);
            }
        }

        //Run bfs
        unordered_set<string> visited;
        list<pair<string, int>> queue = {{beginWord, 1}};
        while (!queue.empty()) {
            auto [currWord, length] = queue.front();
            queue.pop_front();
            if (visited.find(currWord) != visited.end()) continue;
            visited.insert(currWord);
            if (currWord == endWord) return length;

            for (int i = 0; i < currWord.size(); ++i) {
                string tempString = currWord.substr(0, i) + "*" + currWord.substr(i+1, currWord.size());
                for (string& nextWord : newWordList[tempString]) {
                    queue.push_back({nextWord, length+1});
                }
            }


        }
        return 0;
    }
};