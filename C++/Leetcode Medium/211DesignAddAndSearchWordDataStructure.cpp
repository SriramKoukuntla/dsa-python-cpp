#include <string>
#include <unordered_map>
using namespace std;
class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node (bool e) {endOfWord = e;}
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {root = new Node(false);}
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) curr->children[c] = new Node(false);
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }

private: 
    bool helper(string& word, int index, Node* curr) {
        if (index == word.size()) return curr->endOfWord;

        if (word[index] == '.') {
            for (auto [c, n] : curr->children) if (helper(word, index+1, n)) return true;
            return false;
        }

        if (curr->children.find(word[index]) == curr->children.end()) return false;

        return helper(word, index+1, curr->children[word[index]]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */