#https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        if not head:
            return 0
        slow, fast, biggestValue = head, head.next, float("-inf")
        prevNode = None
        while fast and fast.next:
            fast = fast.next.next
            nextNode = slow.next
            slow.next = prevNode
            prevNode = slow
            slow = nextNode
        slow2 = slow.next
        slow.next = prevNode
        while slow:
            biggestValue = max(biggestValue, slow.val + slow2.val)
            slow = slow.next; slow2 = slow2.next
        return biggestValue
