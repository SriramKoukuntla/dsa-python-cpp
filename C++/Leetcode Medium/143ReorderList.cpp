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
        //Identify length of list
        int length = 0;
        for (ListNode* curr = head; curr; curr = curr->next) ++length;
        if (length == 1) return;

        //Reach the end of the first half and the start of the second half
        ListNode* endOfFirstHalf = head;
        ListNode* startOfSecondHalf = head; 
        for (int i = 0; i < (length/2)-1; ++i) endOfFirstHalf = endOfFirstHalf->next;
        for (int i = 0; i < length/2; ++i) startOfSecondHalf = startOfSecondHalf->next;

        //Make end of first half point to nothing
        endOfFirstHalf->next = nullptr;

        //Reverse startOfSecondHalf list
        ListNode* prev = nullptr;
        while (startOfSecondHalf) {
            ListNode* next = startOfSecondHalf->next;
            startOfSecondHalf->next = prev;
            prev = startOfSecondHalf;
            startOfSecondHalf = next;
        }

        //Combine both lists
        ListNode* dummyHead = new ListNode();
        ListNode* list1 = head;
        ListNode* list2 = prev;
        ListNode* curr = dummyHead;

        while (list1 && list2) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
        if (list1) curr->next = list1;

        delete dummyHead;
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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* next = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = next;
        }
        ListNode* headOfSecondHalf = prev;

        ListNode* headOne = head;
        ListNode* headTwo = headOfSecondHalf;

        while (headTwo) {
            ListNode* headOneNext = headOne->next;
            ListNode* headTwoNext = headTwo->next;

            headOne->next = headTwo;
            headTwo->next = headOneNext;

            headOne = headOneNext;
            headTwo = headTwoNext;
        }
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
    void reorderList(ListNode* head) {
        //Find middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //Reverse second half of list;
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; //This makes first half have an end
        ListNode* prev = nullptr; //This make second half have an end
        ListNode* curr = secondHalf;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* tail = prev;

        //Combine both lists;
        ListNode* dummy = new ListNode();
        ListNode* headCurr = head;
        ListNode* tailCurr = tail;
        while (headCurr && tailCurr) {
            dummy->next = headCurr;
            headCurr = headCurr->next;
            dummy = dummy->next;

            dummy->next = tailCurr;
            tailCurr = tailCurr->next;
            dummy = dummy->next;
        }
        
        //If odd head will have one more to append
        if (headCurr) dummy->next = headCurr;
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