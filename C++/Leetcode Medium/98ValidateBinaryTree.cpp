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
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        //pair<pair<left range, right range>, pair<what child, currentNode>>
        //true == left child, false == right child
        vector<pair<pair<long long, long long>, TreeNode*>> stack = {{{LLONG_MIN, LLONG_MAX}, root}};
    
        while (!stack.empty()) {
            pair<pair<long long, long long>, TreeNode*> curr = stack.back();
            stack.pop_back();
            long long leftRange = curr.first.first;
            long long rightRange = curr.first.second;
            TreeNode* node = curr.second;


            if (!(leftRange < node->val && node->val < rightRange)) return false;
            if (node->left) stack.push_back({{leftRange, node->val}, node->left});
            if (node->right) stack.push_back({{node->val, rightRange}, node->right});
        }
        return true;
    }
};