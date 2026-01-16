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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyList = new ListNode(0, head);
        ListNode* fast = dummyList;
        ListNode* slow = dummyList;
        for (int i = 0; i < n+1; ++i) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyList->next;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Go through the list to find the size
        //Remove the node
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            ++size;
            curr = curr->next;
        }
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        curr = dummy;
        int z = size-n;
        for (int i = 0; i < z; ++i) {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return dummy->next;
    }
};