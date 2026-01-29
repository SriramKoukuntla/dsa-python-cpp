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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* b = dummyNode;
        ListNode* f = head;
        int n = 1;
        while (n != left) {
            b = b->next;
            f = f->next;
            ++n;
        }

        ListNode* curr = f;
        ListNode* prev = nullptr;
        while (n != right) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++n;
        }
        ListNode* After = curr->next;
        curr->next = prev;
        prev = curr;
        curr = After;

        b->next = prev;
        f->next = After;

        return dummyNode->next;
    }
};