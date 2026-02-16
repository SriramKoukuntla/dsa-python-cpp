// Definition for singly-linked list.
#include <utility>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthOfListA = 0;
        for (ListNode* curr = headA; curr; curr = curr->next) ++lengthOfListA;

        int lengthOfListB = 0;
        for (ListNode* curr = headB; curr; curr = curr->next) ++lengthOfListB;





        ListNode* currA = headA;
        ListNode* currB = headB;
        if (lengthOfListB > lengthOfListA) {swap(currA, currB); swap(lengthOfListA, lengthOfListB);}
        while (lengthOfListA > lengthOfListB) {
            currA = currA->next;
            --lengthOfListA;
        }

        while (currA && currB && currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }
        return currA;


    }
};