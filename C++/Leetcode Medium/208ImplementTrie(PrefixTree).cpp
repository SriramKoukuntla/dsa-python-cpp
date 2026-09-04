#include <string>
#include <unordered_map>
using namespace std;
class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node(bool endOfWord) {endOfWord = endOfWord;}
};

class Trie {
public:
    Node* root;
    Trie() {root = new Node(false);}
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) curr->children[c] = new Node(false);
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
#include <unordered_map>
class Node {
public:
    Node* parent;
    unordered_map<char, Node*> children;
    char letter;
    Node() : parent(nullptr), letter('\0') {}
    Node(Node* parent, char letter) : parent(parent), letter(letter) {}
};

class Trie {
public:
    Node* parent;
    Trie() {
        parent = new Node();
    }
    
    void insert(string word) {
        word += '\0';
        Node* curr = parent;
        for (char letter : word){
            //If node already created
            if (curr->children.find(letter) != curr->children.end()){
                curr = curr->children[letter];
            }
            //If node doesn't exist
            else{
                curr->children[letter] = new Node(curr, letter);
                curr = curr->children[letter];
            }
        }
    }
    
    bool search(string word) {
        word += '\0';
        Node *curr = parent;
        for (char letter : word){
            if (curr->children.find(letter) == curr->children.end()){
                return false;
            }
            curr = curr->children[letter];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = parent;
        for (char letter : prefix){
            if (curr->children.find(letter) == curr->children.end()){
                return false;
            }
            curr = curr->children[letter];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */