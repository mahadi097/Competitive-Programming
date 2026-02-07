# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        exist = set(nums)
        
        prv, cur = None, head
        while cur != None:
            if cur.val not in exist:
                prv = cur
                cur = cur.next
            else:
                if cur == head:
                    cur = cur.next
                    head = cur
                else:
                    prv.next = cur.next
                    cur = cur.next
        
        return head