#include <queue>
using namespace std;
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> queue; 
        queue.push(root);
        while (!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            if (curr==nullptr) continue;
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            queue.push(curr->left);
            queue.push(curr->right);
        }
        return root;
    }
};