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
#include <algorithm>
#include <cstdlib>
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return helper(root).second;
    }
    pair<int, bool> helper(TreeNode* node) {
        if (!node) return {0, true};
        if (!node->left && !node->right) return {1, true};
        pair<int, bool> leftSubTree = helper(node->left);
        pair<int, bool> rightSubTree = helper(node->right);
        bool balanced = (leftSubTree.second && rightSubTree.second) && (abs(leftSubTree.first-rightSubTree.first)<=1);
        return {max(leftSubTree.first, rightSubTree.first)+1, balanced};
    }
};