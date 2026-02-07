# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def get_total() -> int:
            total = 0
            q = deque()
            q.append(root)

            while len(q) > 0:
                node = q.popleft()
                total += node.val
                if node.left != None:
                    q.append(node.left)
                if node.right != None:
                    q.append(node.right)
            return total
        
        total_sum = get_total()
        max_product = 0

        def traverse(node: Optional[TreeNode]) -> int:
            nonlocal max_product
            if node == None:
                return 0
            sub_sum = node.val
            sub_sum += traverse(node.left)
            sub_sum += traverse(node.right)
            product = sub_sum * (total_sum-sub_sum)
            if product > max_product:
                max_product = product

            return sub_sum
        
        traverse(root)

        max_product %= 10**9 + 7
        return max_product