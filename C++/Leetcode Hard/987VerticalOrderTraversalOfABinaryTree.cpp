#include <vector>
#include <algorithm>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& tuplesList) {
        tuplesList.push_back({col, row, node->val});
        if (node->left) helper(node->left, row+1, col-1, tuplesList);
        if (node->right) helper(node->right, row+1, col+1, tuplesList);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //Create list of tuples each node should have corresponding <col, row, val>
        vector<tuple<int, int, int>> tuplesList;
        helper(root, 0, 0, tuplesList);
        //Sorted by col, row, val
        sort(tuplesList.begin(), tuplesList.end());



        //Create res list
        vector<vector<int>> res;
        int prevCol = get<0>(tuplesList[0]);
        vector<int> temp = {get<2>(tuplesList[0])};
        for (int i = 1; i < tuplesList.size(); ++i) {
            if (get<0>(tuplesList[i]) == prevCol) temp.push_back(get<2>(tuplesList[i]));
            else {
                res.push_back(temp);
                temp = {};

                prevCol = get<0>(tuplesList[i]);
                temp.push_back(get<2>(tuplesList[i]));
            }
        }
        res.push_back(temp);

        return res; 

    }
};