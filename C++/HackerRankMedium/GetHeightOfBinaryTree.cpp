#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;
vector<int> processInput() {
    string nonSense;
    getline(cin, nonSense);
    
    string nodesStr = "-1";
    getline(cin, nodesStr);
    vector<int> input;
    
    string temp = "";
    for (int i = 0; i < nodesStr.size() + 1; ++i) {
        if (i == nodesStr.size() || nodesStr[i] == ' ') {
            input.push_back(stoi(temp));
            temp = "";
        }
        else if (nodesStr[i] != ' ') temp += nodesStr[i];
    }
    
    return input;
}

class Node {
public:
    Node* left;
    Node* right;
    int val;
    Node(int v) : left(nullptr), right(nullptr), val(v) {}
};

int main() {
    //Process input
    vector<int> inputs = processInput();

    Node* root = new Node(inputs[0]);
    for (int i = 1; i < inputs.size(); ++i) {
        Node* curr = root;
        int input = inputs[i];
        while (true) {
            Node*& child = (input <= curr->val) ? curr->left : curr->right;
            if (!child) { child = new Node(input); break; }
            curr = child;
        }  
    }
    
    //Check if the tree if formatted correctly
    list<Node*> queue = {root};
    int res = -1;
    while (!queue.empty()) {
        int n = queue.size();
        for (int i = 0; i < n; ++i) {
            Node* curr = queue.front();
            queue.pop_front();
            if (curr->left) queue.push_back(curr->left);
            if (curr->right) queue.push_back(curr->right);
        }
        ++res;
    }
    
    cout << res;
    
    return 0;
}