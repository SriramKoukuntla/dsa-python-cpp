struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* prev = dummyHead;
        ListNode* curr = dummyHead->next;

        ListNode* dummyHeadList2 = new ListNode(-1);
        ListNode* curr2 = dummyHeadList2;

        while (curr) {
            if (curr->val < x) {
                curr2->next = curr;
                curr2 = curr2->next;
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        curr2->next = dummyHead->next;
        delete dummyHead;
        
        ListNode* res = dummyHeadList2->next;
        delete dummyHeadList2;

        return res;
    }
};
//First pass we append nodes less than x
//Second pass we get everything else