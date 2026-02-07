# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mx_lvl = 1
        lvl_sum = defaultdict(int)
        
        def traverse(node: Optional[TreeNode], lvl: int) -> None:
            nonlocal mx_lvl
            if node == None:
                return
            mx_lvl = max(mx_lvl, lvl)
            lvl_sum[lvl] += node.val

            traverse(node.left, lvl+1)
            traverse(node.right, lvl+1)
        
        traverse(root, 1)

        mx_sum, lvl = -inf, 1
        for i in range(1, mx_lvl+1):
            if lvl_sum[i] > mx_sum:
                mx_sum = lvl_sum[i]
                lvl = i
        
        return lvl