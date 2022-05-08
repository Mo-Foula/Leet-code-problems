# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is not None and l2 is not None:
            if l1.val < l2.val:
                newL = ListNode(l1.val)
                l1 = l1.next
            else:
                newL = ListNode(l2.val)
                l2 = l2.next
        else:
            if l1 is not None:
                newL = ListNode(l1.val)
                l1 = l1.next
            elif l2 is not None:
                newL = ListNode(l2.val)
                l2 = l2.next
            else: newL = None
        temp = newL
        while l1 is not None and l2 is not None:
            if l1.val < l2.val:
                temp.next = ListNode(l1.val)
                temp = temp.next
                l1 = l1.next
            else:
                temp.next = ListNode(l2.val)
                temp = temp.next
                l2 = l2.next
        while l1 is not None:
            temp.next = ListNode(l1.val)
            temp = temp.next
            l1 = l1.next
        while l2 is not None:
            temp.next = ListNode(l2.val)
            temp = temp.next
            l2 = l2.next
        return newL