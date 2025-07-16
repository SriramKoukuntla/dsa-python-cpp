#include <algorithm>
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
    int res;

    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }

private:
    int helper(TreeNode* root){
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res = max(res, left+right);
        return 1 + max(left, right);
    }
};


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }

private:
    int helper(TreeNode* root, int& res){
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(res, left+right);
        return 1 + max(left, right);
    }
};