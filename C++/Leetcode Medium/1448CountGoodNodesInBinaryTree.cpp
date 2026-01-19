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
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        vector<pair<int, TreeNode*>> stack = {{-99999, root}};
        while (!stack.empty()) {
            pair<int, TreeNode*> curr = stack.back();
            stack.pop_back();
            if (curr.second->val >= curr.first) ++res;
            int val = max(curr.first, curr.second->val);
            if (curr.second->left) stack.push_back({val, curr.second->left});
            if (curr.second->right) stack.push_back({val, curr.second->right});
        }
        return res;
    }
};