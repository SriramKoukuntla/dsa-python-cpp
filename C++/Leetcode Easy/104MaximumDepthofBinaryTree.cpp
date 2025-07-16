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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* root, int level){
        if (root == nullptr) return level;
        int left = helper(root->left, level+1);
        int right = helper(root->right, level+1);
        return left > right ? left : right;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + (left > right ? left : right);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<tuple<TreeNode*, int>> q;
        int res = 0;
        q.emplace(root, 1));
        while (!q.empty()){
            auto [node, level] = q.front();
            q.pop();
            if (node == nullptr) continue;
            res = (res > level ? res : level);
            q.emplace(node->left, level+1);
            q.emplace(node->right, level+1);
        }
        return res;
    }
};