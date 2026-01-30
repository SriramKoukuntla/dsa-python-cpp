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
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        list<TreeNode*> queue = {root};
        while (!queue.empty()) {
            int n = queue.size();
            ++res;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = queue.front();
                queue.pop_front();
                if (!curr->left && !curr->right) return res;
                if (curr->left) queue.push_back(curr->left);
                if (curr->right) queue.push_back(curr->right);
            }
        }
        return -1;
    }
};