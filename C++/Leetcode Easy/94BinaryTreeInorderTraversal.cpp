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
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sk;
        TreeNode* curr = root;
        while (curr || !sk.empty()) {
            while (curr) {
                sk.push(curr);
                curr = curr->left;
            }
            curr = sk.top();
            sk.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
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
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
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
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (!st.empty() || curr) {
            //go to the left most
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            //proccess current node
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            //add right node to stack
            curr = curr->right;
        }
        return res;
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
 #include <vector>
 using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        vector<int> left = inorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};

//process left node
//proccess curr
//process right node