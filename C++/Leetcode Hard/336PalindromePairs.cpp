#include <vector>
#include <string>
using namespace std;
class TrieNode {
public:
    vector<TrieNode*> children;
    vector<int> palPrefixIdx;   // indices whose remaining prefix is palindrome at this node
    int wordIndex;              // word whose reversed form ends here
    char c;

    TrieNode() : children(26, nullptr), wordIndex(-1), c('/') {}
    TrieNode(char letter) : children(26, nullptr), wordIndex(-1), c(letter) {}
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* head = new TrieNode();

        // Insert each word in reversed order
        for (int i = 0; i < (int)words.size(); ++i) {
            insert(head, words[i], i);
        }

        vector<vector<int>> res;

        // Search each word
        for (int j = 0; j < (int)words.size(); ++j) {
            search(head, words[j], j, res);
        }

        return res;
    }

private:
    void insert(TrieNode* head, const string& w, int idx) {
        TrieNode* node = head;
        int n = (int)w.size();

        // walk w from end -> start (i.e., insert reversed w)
        for (int j = n - 1; j >= 0; --j) {
            // IMPORTANT: if prefix w[0..j] is palindrome,
            // then any word that ends at this node can pair with w
            if (isPalindrome(w, 0, j)) {
                node->palPrefixIdx.push_back(idx);
            }

            int c = w[j] - 'a';
            if (!node->children[c]) node->children[c] = new TrieNode(w[j]);
            node = node->children[c];
        }

        // whole word ended here
        node->wordIndex = idx;

        // empty prefix is palindrome too => store for exact matches
        node->palPrefixIdx.push_back(idx);
    }

    void search(TrieNode* head, const string& w, int idx, vector<vector<int>>& res) {
        TrieNode* node = head;
        int n = (int)w.size();

        for (int i = 0; i < n; ++i) {
            // If some reversed-word ends here, and the remaining suffix of w is palindrome,
            // then w + thatWord is a valid pair.
            if (node->wordIndex != -1 && node->wordIndex != idx && isPalindrome(w, i, n - 1)) {
                res.push_back({idx, node->wordIndex});
            }

            int c = w[i] - 'a';
            if (!node->children[c]) return; // dead end
            node = node->children[c];
        }

        // We've consumed all of w. Now any word index stored in palPrefixIdx
        // corresponds to a word whose remaining prefix (in original orientation) is palindrome.
        for (int other : node->palPrefixIdx) {
            if (other != idx) res.push_back({idx, other});
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};