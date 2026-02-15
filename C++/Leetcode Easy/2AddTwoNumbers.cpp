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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int overFlowSum = 0;
        while (l1 || l2  || overFlowSum) {
            int val = overFlowSum;
            if (l1) {val += l1->val; l1 = l1->next;}
            if (l2) {val += l2->val; l2 = l2->next;}
            overFlowSum = (val >= 10) ? 1 : 0;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
        }   
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

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
        ListNode* dummy = new ListNode();
        int overFlow1 = 0;
        ListNode* curr = dummy;
        for (; l1 && l2; curr = curr->next) {
            int val = l1->val + l2->val + overFlow1;
            if (val >= 10) overFlow1 = 1;
            else overFlow1 = 0;
            curr->next = new ListNode(val % 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1 && !l2 && overFlow1) curr->next = new ListNode(1);
        else if ((l1 || l2) && !overFlow1) if (l1) curr->next = l1; else curr->next = l2;
        else if ((l1 || l2) && overFlow1) {
            ListNode* append = l1 ? l1 : l2;
            for (; append; append = append->next) {
                int val = append->val + overFlow1;
                if (val >= 10) overFlow1 = 1;
                else overFlow1 = 0;
                curr->next = new ListNode(val % 10);
                curr = curr->next;
            }

            if (overFlow1) curr->next = new ListNode(1);


        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};