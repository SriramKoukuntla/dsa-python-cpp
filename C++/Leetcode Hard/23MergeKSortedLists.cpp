/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* head : lists) if (head) pq.push({head->val, head});
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto [nodeVal, node] = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            ListNode* nextNode = node->next;
            if (nextNode) pq.push({nextNode->val, nextNode});
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};


/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* list : lists) if (list) pq.push({list->val, list});

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto [currVal, currNode] = pq.top();
            pq.pop();

            curr->next = currNode;
            curr = curr->next;

            if (currNode->next) pq.push({curr->next->val, curr->next});
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};