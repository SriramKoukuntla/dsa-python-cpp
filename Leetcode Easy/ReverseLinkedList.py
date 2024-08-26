#https://leetcode.com/problems/reverse-linked-list/description/
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#ITERATIVE SOLUTION
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        if head.next == None:
            return head
        else:
            newHead = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return newHead 
#RECURSIVE SOLUTION
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        if head.next == None:
            return head
        if head.next != None:
            newHead = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return newHead