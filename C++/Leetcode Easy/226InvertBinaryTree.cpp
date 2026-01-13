//2 ways do both

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
        if (root == nullptr) return root;
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        TreeNode* temp= root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

#include <list>
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
        list<TreeNode*> queue;
        queue.push_back(root);
        while (queue.size() != 0) {
            TreeNode* curr = queue.front();
            queue.pop_front();
            if (!curr) continue;
            TreeNode* Temp = curr->left;
            curr->left = curr->right;
            curr->right = Temp;
            queue.push_back(curr->left);
            queue.push_back(curr->right);
        }
        return root;
    }
};


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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left); 
        invertTree(root->right); 
        return root;
    }
};