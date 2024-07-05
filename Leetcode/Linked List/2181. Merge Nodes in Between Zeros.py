# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prv_node, cur_node = None, head
        
        while cur_node != None:
            if cur_node.val == 0:
                cur_node = cur_node.next
                continue

            if prv_node != None:
                prv_node.next = cur_node

            node_now = cur_node.next
            while node_now.val != 0:
                cur_node.val += node_now.val
                node_now = node_now.next
            
            prv_node = cur_node
            prv_node.next = None
            cur_node = node_now

        return head.next
        