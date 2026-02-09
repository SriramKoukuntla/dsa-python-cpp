class Node {
public: 
    Node* left = nullptr; //you need to be assigning values to these or else they will be fill with garbage values
    Node* right = nullptr;
    int val = 0;
    Node() = default;
    Node(int v) : val(v){};
private: 

};