#https://leetcode.com/problems/reverse-linked-list-ii/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummyNode = ListNode(0, head)
        curr = dummyNode
        front = curr.next
        for __ in range(left-1):
            curr = curr.next
            front = front.next
        prev = None
        nextN = None
        for __ in range(right-left+1):
            nextN = front.next
            front.next = prev
            prev = front
            front = nextN
        curr.next.next = nextN
        curr.next = prev
        return dummyNode.next
    


# class Solution:
#     def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
#         length = 0
#         curr = head
#         while curr:
#             curr = curr.next
#             length += 1
        
#         if left < 0 or left > length or right < 0  or right > length:
#             return head
        
#         dummyNode = ListNode(0, head)
#         curr = dummyNode
#         idx = 0
#         for __ in range(left-1):
#             curr = curr.next
#             idx += 1

#         def helper(prev, curr, counter):
#             nextN = curr.next
#             curr.next = prev
#             if counter != right:
#                 return helper(curr, nextN, counter+1)
#             else:
#                 endOfReverse.next = nextN
#                 return curr
#         endOfReverse = curr.next
#         curr.next = helper(None, curr.next, idx+1)
#         return dummyNode.next