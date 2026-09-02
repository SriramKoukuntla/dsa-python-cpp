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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            if (curr->left) st.push(curr->left);
            if (curr->right) st.push(curr->right);

        }

        reverse(result.begin(), result.end());
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sk;
        stack<bool> visit;
        sk.push(root);
        visit.push(false);
        while (!sk.empty()) {
            TreeNode* curr = sk.top();
            sk.pop();
            bool visited = visit.top();
            visit.pop();
            if (!curr) continue;
            if (visited) result.push_back(curr->val);
            else {
                sk.push(curr);
                visit.push(true);
                sk.push(curr->right);
                visit.push(false);
                sk.push(curr->left);
                visit.push(false);
            }
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        stack<bool> visited;
        sk.push(root);
        visited.push(false);
        while (!sk.empty()) {
            TreeNode* curr = sk.top();
            bool visit = visited.top();
            sk.pop();
            visited.pop();
            if (curr == nullptr) continue;
            if (visit) res.push_back(curr->val);
            else {
                sk.push(curr);
                visited.push(true);
                sk.push(curr->right);
                visited.push(false);
                sk.push(curr->left);
                visited.push(false);
            }
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        vector<int> left = postorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
    }
};