#include <unordered_set>
#include <string>
using namespace std;
class TrieNode {
public: 
    char c;
    vector<TrieNode*> children;
    bool end;
    string word;
    TrieNode() : c('/'), children(26, nullptr), end(false), word("") {}
    TrieNode(string w, char letter) : c(letter), children(26, nullptr), end(false), word(w) {}
};

class Solution {
public:
    void dfs (int i, int j, TrieNode* currNode, unordered_set<string>& res, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) return;
        if (currNode->children[board[i][j]-'a'] == nullptr) return;
        visited[i][j] = true;
        
        currNode = currNode->children[board[i][j]-'a'];
        if (currNode->end) res.insert(currNode->word);

        dfs(i-1, j, currNode, res, visited, board);
        dfs(i, j+1, currNode, res, visited, board);
        dfs(i+1, j, currNode, res, visited, board);
        dfs(i, j-1, currNode, res, visited, board);
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //Create Trie for words
        TrieNode* head = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* curr = head;
            string currWordSubstr;
            for (int j = 0; j < words[i].size(); ++j) {
                currWordSubstr += words[i][j];
                if (curr->children[words[i][j]-'a'] == nullptr) curr->children[words[i][j]-'a'] = new TrieNode(currWordSubstr, words[i][j]);
                curr = curr->children[words[i][j]-'a'];
            }
            curr->end = true;
        }

        //Run Dfs on every single tile
        unordered_set<string> temp;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, head, temp, visited, board);
            }
        }

        vector<string> res(temp.begin(), temp.end());
        return res;
    }
};