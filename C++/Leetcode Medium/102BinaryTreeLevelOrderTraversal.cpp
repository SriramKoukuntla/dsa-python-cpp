/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <list>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res; 
        list<TreeNode*> queue = {root};
        while (!queue.empty()) {
            vector<int> layer;
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = queue.front();
                queue.pop_front();
                layer.push_back(curr->val);
                if (curr->left) queue.push_back(curr->left);
                if (curr->right) queue.push_back(curr->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};