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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            } 
            curr = curr->next;
        }
        curr->next = (list1 != nullptr) ? list1 : list2;
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

//Recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        return (list1->val < list2->val)
         ? (list1->next = mergeTwoLists(list1->next, list2), list1)
         : (list2->next = mergeTwoLists(list1, list2->next), list2);
    }
};

//No dummy node
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head;
        ListNode* tail;

        if (list1->val < list2->val){
            head = tail = list1;
            list1 = list1->next;
        }
        else{
            head = tail = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;
        return head;
    }
};