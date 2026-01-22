/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> map; //{parent, child};
        vector<pair<TreeNode*, TreeNode*>> stack = {{nullptr, root}};
        while (!stack.empty()) {
            pair<TreeNode*, TreeNode*> p = stack.back();
            stack.pop_back();
            map[p.second] = p.first;
            if (p.second->left) stack.push_back({p.second, p.second->left});
            if (p.second->right) stack.push_back({p.second, p.second->right});
        }

        TreeNode* curr = p;
        unordered_set<TreeNode*> visited;
        while (curr) {
            visited.insert(curr);
            curr = map[curr];
        }

        curr = q;
        while (curr) {
            if (visited.find(curr) != visited.end()) return curr;
            curr = map[curr];
        }
        return nullptr;
    }
};