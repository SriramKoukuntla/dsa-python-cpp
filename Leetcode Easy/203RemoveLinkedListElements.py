#https://leetcode.com/problems/remove-linked-list-elements/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#General Solution
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummyNode = ListNode(-1)
        dummyNode.next = head
        curr = dummyNode
        while curr.next != None:
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummyNode.next
    

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head == None:
            return head
        lead = head.next
        follow = head
        while lead != None:
            if lead.val == val:
                lead = lead.next
                follow.next = lead
            else:
                lead = lead.next
                follow = follow.next
        
        if head.val == val:
            return head.next
        return head 
    