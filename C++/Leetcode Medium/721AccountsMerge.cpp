#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findOp(vector<int>& uf, vector<int>& ufSize, int node) {
        if (uf[node] == node) return node;
        else return uf[node] = findOp(uf, ufSize, uf[node]);
    }

    bool unionOp(vector<int>& uf, vector<int>& ufSize, int node1, int node2) {
        int root1 = findOp(uf, ufSize, node1);
        int root2 = findOp(uf, ufSize, node2);
        if (root1 == root2) return false;
        if (ufSize[root2] > ufSize[root1]) swap(root1, root2);
        ufSize[root1] += ufSize[root2];
        uf[root2] = root1;
        return true;
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> uf;
        vector<int> ufSize(accounts.size(), 1);
        for (int i = 0; i < accounts.size(); ++i) uf.push_back(i);

        unordered_map<string, int> map; //key = email, value = index of node it represents in uf
        for (int i = 0; i < accounts.size(); ++i) {
            vector<string>& currAccount = accounts[i];
            for (int j = 1; j < currAccount.size(); ++j) {
                string& currEmail = currAccount[j];
                if(map.find(currEmail) == map.end()) {
                    map[currEmail] = i;
                }
                else {
                    unionOp(uf, ufSize, map[currEmail], i);
                }
            }
        }

        unordered_map<int, unordered_set<string>> resMap;
        for (auto& [email, id] : map) resMap[findOp(uf, ufSize, id)].insert(email);


        vector<vector<string>> res;
        for (auto& [id, account] : resMap) {
            vector<string> toBePushed = {accounts[id][0]};
            for (string email : account) toBePushed.push_back(email);
            sort(toBePushed.begin()+1, toBePushed.end());
            res.push_back(toBePushed);
        }

        return res;
    }
};