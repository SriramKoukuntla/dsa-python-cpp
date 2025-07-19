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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while (slow != nullptr){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* head1 = head;
        ListNode* head2 = prev;

        while (true){
            if (head1 == head2) break; //even case
            if (head1->next == head2) break; //odd case
            ListNode* head1Next = head1->next;
            head1->next = head2;
            ListNode* head2Next = head2->next;
            head2->next = head1Next;
            head1 = head1Next;
            head2 = head2Next;
        }
    }
};