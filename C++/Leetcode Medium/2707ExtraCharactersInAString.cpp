#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Node {
public:
    bool endOfWord;
    unordered_map<char, Node*> children;
    Node(bool b) {endOfWord = b;}
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        //Create Trie
        Node* root = new Node(false);
        for (string& word : dictionary) {
            Node* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) curr->children[c] = new Node(false);
                curr = curr->children[c];
            }
            curr->endOfWord = true;
        }

        //Solve every subproblem
        vector<int> subProblems(s.size()+1, 0); //index represents size of subproblem. value represents solution to subproblem
        for (int i = 1; i <= s.size(); ++i) {
            string currString = s.substr(s.size()-i, i);
            int res = 1 + subProblems[i-1];
            Node* curr = root;
            for (int j = 0; j < currString.size(); ++j) {
                if (curr->children.find(currString[j]) == curr->children.end()) break;
                curr = curr->children[currString[j]];
                if (curr->endOfWord) res = min(res, subProblems[i-(j+1)]);
            }
            subProblems[currString.size()] = res;
        }

        // //Return biggest subproblem
        return subProblems.back();
    }
};