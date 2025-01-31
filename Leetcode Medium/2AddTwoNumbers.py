#https://leetcode.com/problems/add-two-numbers/description/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode()
        head1, head2, retHead = l1, l2, ret
        overFlow = 0
        while head1 != None and head2 != None:
            Val = head1.val + head2.val + overFlow
            overFlow = Val//10
            retHead.next = ListNode(val = Val%10)
            retHead = retHead.next
            head1, head2 = head1.next, head2.next
        while head1 != None or head2 != None:
            if head1 != None:
                Val = overFlow + head1.val
                head1 = head1.next
            else: 
                Val = overFlow + head2.val
                head2 = head2.next
            overFlow = Val//10
            retHead.next = ListNode(val = Val%10)
            retHead = retHead.next 
        if overFlow != 0:
            retHead.next = ListNode(val = 1)
            retHead = retHead.next 
        return ret.next
