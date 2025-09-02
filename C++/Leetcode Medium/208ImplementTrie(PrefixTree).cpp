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