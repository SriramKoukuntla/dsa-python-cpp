#https://leetcode.com/problems/palindrome-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        def helper(curr, prev):
            if curr == None:
                return prev
            nextN = curr.next
            curr.next = prev
            return helper(nextN, curr)
        left = head
        right = helper(slow, None)
        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        return True
    
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        stack = []
        slow = head
        fast = head
        while fast and fast.next:
            stack.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next
        while slow:
            if stack.pop() != slow.val:
                return False
            slow = slow.next
        return True