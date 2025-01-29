#https://leetcode.com/problems/copy-list-with-random-pointer/description/
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        dictionary = {}
        curr = head
        dummyHead = Node(10)
        copyCurr = dummyHead
        while curr != None:
            temp = Node(curr.val, curr.next)
            copyCurr.next = temp
            dictionary[curr] = temp
            copyCurr = copyCurr.next
            curr = curr.next
        #We have now copied everything except random
        curr = head
        copyCurr = dummyHead
        while curr != None:
            copyCurr = copyCurr.next
            if curr.random == None:
                copyCurr.random = None
            else:
                copyCurr.random = dictionary[curr.random]
            curr = curr.next
        return dummyHead.next