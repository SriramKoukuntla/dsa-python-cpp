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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int onesRemainder = 0;
        ListNode* l1Curr = l1;
        ListNode* l2Curr = l2;
        ListNode* dummy = new ListNode();
        ListNode* resCurr = dummy;
        while (l1Curr || l2Curr || onesRemainder) {
            int sum = onesRemainder;
            if (l1Curr) {
                sum += l1Curr->val;
                l1Curr = l1Curr->next;
            }
            if (l2Curr) {
                sum += l2Curr->val;
                l2Curr = l2Curr->next;
            }
            resCurr->next = new ListNode(sum % 10);
            resCurr = resCurr->next;
            if (sum > 9) onesRemainder = 1;
            else onesRemainder = 0;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};