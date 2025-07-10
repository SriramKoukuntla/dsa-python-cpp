#https://leetcode.com/problems/-linked-list/description/
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#ITERATIVE SOLUTION
class Solution(object):
    def List(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        if head.next == None:
            return head
        else:
            newHead = self.List(head.next)
            head.next.next = head
            head.next = None
            return newHead 
#RECURSIVE SOLUTION
class Solution(object):
    def List(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        if head.next == None:
            return head
        if head.next != None:
            newHead = self.List(head.next)
            head.next.next = head
            head.next = None
            return newHead

#Better Recursive Solution
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def helper(head, prev):
            if head == None:
                return prev
            nextN = head.next
            head.next = prev
            return helper(nextN, head)
        return helper(head, None)