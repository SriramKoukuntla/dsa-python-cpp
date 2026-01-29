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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = new ListNode(-1, head);
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            temp = temp->next;
        }
        temp->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* curr1 = head;
        ListNode* curr2 = prev;
        while (curr1 && curr2) {
            if (curr1->val != curr2->val) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;


    }
};