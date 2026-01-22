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
#include <list>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        list<TreeNode*> queue = {root};
        vector<int> res;
        while (!queue.empty()) {
            int n = queue.size();
            res.push_back(queue.front()->val);
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = queue.front();
                queue.pop_front();
                if (curr->right) queue.push_back(curr->right);
                if (curr->left) queue.push_back(curr->left);
            }
        }
        return res;
    }
};