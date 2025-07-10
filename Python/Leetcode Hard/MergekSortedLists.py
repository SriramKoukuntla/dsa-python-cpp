#https://leetcode.com/problems/merge-k-sorted-lists/description/
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        pointersList = []
        for i in range(len(lists)):
            if lists[i]:
                pointersList.append(lists[i])
        #Createing list of pointers

        finalList = ListNode()
        current = finalList
        #List we will return

        while True:
            minVal = float('inf')
            index = -1
            for i in range(len(pointersList)):
                if pointersList[i] != None:
                    if pointersList[i].val < minVal:
                        index = i
                        minVal = pointersList[i].val

            if index == -1:
                break
            else:
                current.next = pointersList[index]
                current = current.next
                pointersList[index] = pointersList[index].next

            if pointersList[index] == None:
                pointersList.pop(index)

        return finalList.next