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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        list<TreeNode*> queue1 = {p};
        list<TreeNode*> queue2 = {q};
        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* curr1 = queue1.front();
            TreeNode* curr2 = queue2.front();
            cout << curr1->val << " || " << curr2->val << endl;
            queue1.pop_front();
            queue2.pop_front();
            if (curr1->val != curr2->val) return false;
            if ((curr1->left == nullptr) != (curr2->left == nullptr)) return false;
            if ((curr1->right == nullptr) != (curr2->right == nullptr)) return false;
            if (curr1->left) {
                queue1.push_back(curr1->left);
                queue2.push_back(curr2->left);
            }
            if (curr1->right) {
                queue1.push_back(curr1->right);
                queue2.push_back(curr2->right);
            }
        }
        return queue1.empty() && queue2.empty();
    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) != (q == nullptr)) return false;
        if (!p && !q) return true;
        if (p->val != q->val) return false;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }
};
#include <queue>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};