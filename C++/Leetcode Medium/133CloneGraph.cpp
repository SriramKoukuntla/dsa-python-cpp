/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> map;
        return helper(node, map);
    }
    Node* helper(Node* node, unordered_map<int, Node*>& map) {
        if (node == nullptr) return nullptr;
        Node* res = new Node(node->val);
        map[node->val] = res;
        for (Node* neighbhor : node->neighbors) {
            if (map.find(neighbhor->val) != map.end()) res->neighbors.push_back(map[neighbhor->val]);
            else res->neighbors.push_back(helper(neighbhor, map));
        }
        return res;
    }
};