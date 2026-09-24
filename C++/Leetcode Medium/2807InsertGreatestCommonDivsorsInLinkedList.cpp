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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            int a = curr->val;
            int b = curr->next->val;
            if (a < b) swap(a, b);
            int gcdVal;
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            gcdVal = a;
            ListNode* next = curr->next;
            ListNode* newOne = new ListNode(gcdVal, next);
            curr->next = newOne;
            curr = next;
        } 
        return head;
    }
};