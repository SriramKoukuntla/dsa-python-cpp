#https://leetcode.com/problems/reorder-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head == None or head.next == None: return

        slow, fast = head, head
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next

        prev = None
        curr = slow.next
        slow.next = None
        while curr != None:
            nextN = curr.next
            curr.next = prev
            prev = curr
            curr = nextN
        head2 = prev

        dummy = ListNode(-100, head)
        tail = dummy
        while head != None and head2 != None:
            tail.next = head
            tail = tail.next
            head = head.next
            tail.next = head2
            tail = tail.next
            head2 = head2.next
        if head != None: tail.next = head
        if head2 != None: tail.next = head2