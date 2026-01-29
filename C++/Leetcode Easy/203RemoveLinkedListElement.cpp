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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* b = dummy;
        ListNode* f = head;
        while (f) {
            if (f->val == val) {
                b->next = f->next;
                ListNode* prev = f;
                f = b->next;
                delete prev;
            }
            else {
                b = b->next;
                f = f->next;
            }
        }
        return dummy->next;
    }
};