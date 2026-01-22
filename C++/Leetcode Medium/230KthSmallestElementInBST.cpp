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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        helper(res, root, k);
        return res;
    }
    void helper(int& res, TreeNode* node, int& k) {
        if (!node) return;
        helper(res, node->left, k);
        if (--k == 0) {
            res = node->val;
            return;
        }
        helper(res, node->right, k);
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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        vector<TreeNode*> stack;
        TreeNode* curr = root;
        while (curr || !stack.empty()) {
            while (curr) {
                stack.push_back(curr);
                curr = curr->left;
            }
            curr = stack.back();
            stack.pop_back();
            ++n;
            if (n == k) return curr->val;
            curr = curr->right;
        }
        return -1;
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        helper(res, root, k);
        return res;

    }

    void helper(int& res, TreeNode* node, int& k) {
        if (node->left) helper(res, node->left, k);
        if (k == 0) return;
        if (--k == 0) {
            res = node->val; 
            return;}
        if (node->right) helper(res, node->right, k);
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        helper(res, root, k);
        return res[k-1];

    }

    void helper(vector<int>& res, TreeNode* node, int k) {
        if (node->left) helper(res, node->left, k);
        res.push_back(node->val);
        if (node->right) helper(res, node->right, k);
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        helper(res, root, k);
        return res[k-1];

    }

    void helper(vector<int>& res, TreeNode* node, int k) {
        if (node->left && node->right){
            helper(res, node->left, k);
            res.push_back(node->val);
            helper(res, node->right, k);
        }
        else if (node->left){
            helper(res, node->left, k);
            res.push_back(node->val);
        }
        else if (node->right) {
            res.push_back(node->val);
            helper(res, node->right, k);
        }
        else {
            res.push_back(node->val);
        }
    }
    
};