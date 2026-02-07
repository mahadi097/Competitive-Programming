# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        point_first, point_last = -1, -1
        min_dis = sys.maxsize

        def is_critical(prv_val, node) -> bool:
            if prv_val == -1 or node.next == None:
                return False
            if node.val > prv_val and node.val > node.next.val:
                return True
            elif node.val < prv_val and node.val < node.next.val:
                return True
            return False

        pos, pos_last_critical, prv_val = 1, -1, -1
        node = head
        while node != None:
            if is_critical(prv_val, node):
                if pos_last_critical == -1:
                    point_first = pos
                else:
                    min_dis = min(min_dis, pos-pos_last_critical)
                    point_last = pos
                pos_last_critical = pos
        
            prv_val = node.val
            pos += 1
            node = node.next
        
        if point_last == -1:
            return [-1, -1]

        max_dis = point_last - point_first
        return [min_dis, max_dis]
        