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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        list<TreeNode*> queue = {root};
        while (!queue.empty()) {
            int n = queue.size();
            double average = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = queue.front();
                if (curr->left) queue.push_back(curr->left);
                if (curr->right) queue.push_back(curr->right);
                queue.pop_front();
                average += curr->val;
            }
            res.push_back(average/n);
        }
        return res;
    }
};