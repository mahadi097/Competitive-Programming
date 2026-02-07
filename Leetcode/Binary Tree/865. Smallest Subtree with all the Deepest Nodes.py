# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        mx_depth = 0
        f = defaultdict(int)

        def traverse(node: Optional[TreeNode], depth: int) -> None:
            nonlocal mx_depth
            if node == None:
                return
            mx_depth = max(mx_depth, depth)
            f[depth] += 1

            traverse(node.left, depth+1)
            traverse(node.right, depth+1)
        
        traverse(root, 0)
        smallest_sub = None
        
        def find_smallest_sub(node: Optional[TreeNode], depth: int) -> int:
            nonlocal smallest_sub
            if node == None:
                return 0
            total_deepest = 0
            if depth == mx_depth:
                total_deepest += 1
            
            total_deepest += find_smallest_sub(node.left, depth+1)
            total_deepest += find_smallest_sub(node.right, depth+1)

            if total_deepest == f[mx_depth] and smallest_sub == None:
                smallest_sub = node
            
            return total_deepest
        
        find_smallest_sub(root, 0)
        
        return smallest_sub